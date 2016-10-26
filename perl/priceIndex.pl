#!/usr/bin/perl
use strict;                  #strict interpretation of code
use warnings FATAL=>qw(all); #Throw errors for marginal behavior
use Switch;

# add these to the program
# - budget settings for this shopping session
# - shopping list check to indicate being over budget
# - if over budget, show line items, subtotal, budget, and how much the subtotal is over the budget
# - create ability to redefine the quantities or remove line items based on name

# - make the printing function output to an html file since the dropbox app has a built in html viewer

my $total = 0;
my %prices;
my @shoppingList;

sub run {
	open(shList, ">shoppingList.html") or die("could not open shopping list for writing");
	print("\nWhat are you thinking about buying? item followed by quantity\n\n");
	print shList ("<!DOCTYPE html>\n<html>\n<head>\n<meta charset=\"utf-8\">\n<title>Shopping list</title>\n</head>\n<body class=\"container\">\n<div class=\"panel panel-info\">\n<div class=\"panel-heading\">\n<h3 class=\"panel-title\">Shopping list</h3>\n</div>\n<div class=\"panel-body\">\n<table class=\"table\">");
	print shList ("<tr><th>Product</th><th>Quantity</th><th>lineTot</th></tr><tr><hr></tr>");
	while (1) {
		my $product = <STDIN>;
		chomp($product);

		if($prices{$product}) {
			my $quantity = <STDIN>;
			chomp($quantity);
			print shList &printHtmlRow($product, $quantity, $prices{$product} * $quantity);
			# print shList ("[]" . $product . "\t\t" . $quantity . "\t\t" . $prices{$product} * $quantity . "\n");
			$total += $prices{$product} * $quantity;
		}
		else{
			if($product eq "exit") {
				my $result = "Subtotal = \$$total";
				print("\n\n" . $result . " \n");
				print shList ("</table></div><div class=\"panel-footer\"><p>" . $result . "</p></div></div></body><footer><!-- Latest compiled and minified CSS --><link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css\" integrity=\"sha384-1q8mTJOASx8j1Au+a5WDVnPi2lkFfwwEAa8hDDdjZlpLegxhjVME1fgjWPGmkzs7\" crossorigin=\"anonymous\"<!-- Optional theme --><link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap-theme.min.css\" integrity=\"sha384-fLW2N01lMqjakBkx3l/M9EahuwpSfeNvV63J5ezn3uZzapT0u7EYsXMjQV+0En5r\" crossorigin=\"anonymous\"<!-- Latest compiled and minified JavaScript --><script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js\" integrity=\"sha384-0mSbJDEHialfmuBBQP6A4Qrprq5OVfW37PRR3j5ELqxss1yVqOtnepnHVP9aJ7xS\" crossorigin=\"anonymous\"></script></footer></html>");
				close(shList);
				die("killing program\n");
			}else{
				print("Add new entry? yes/else ");
				my $choice = <STDIN>;
				chomp($choice);
				if($choice eq "yes"){
					print("Whatis the unit price? ");
					my $price = <STDIN>;
					chomp($price);

					print("how many? ");
					my $quantity = <STDIN>;
					chomp($quantity);

					# save new product entry
					open(indxSrc, ">>index") or die("couldn't open index file");
					print indxSrc ($product . "," . $price . "\n");
					close(indxSrc);

					$prices{$product} = $price;
					print shList &printHtmlRow($product, $quantity, $prices{$product} * $quantity);
					$total += $prices{$product} * $quantity;
				}
			}
		}
	}
}

# sub addProduct {
#
# }

sub printPrices {
	my $toggle = 1;
	open(outFile, ">options") or die("couldn't open output.txt for writing");
	print outFile ("\nExisting options are:\n\n");
	# sort(keys %prices);
	# my @sorted_keys = sort { $breakfast_hash{$a} cmp $breakfast_hash{$b} } keys %breakfast_hash;
	# foreach my $key (@sorted_keys) {
	#   print "$key likes $breakfast_hash{$key} for breakfast.\n";
	# }

	foreach my $key (%prices){
		($toggle)? print outFile ($key . "\n"): print "";
		$toggle = ! $toggle;
	}
	close(outFile);
}

sub constrPricesHash {
	while (my $line = <indexFile>) {
		chomp($line);
		my @tmp = split(",", $line);
		$prices{$tmp[0]} = $tmp[1];
	}
}

sub printHtmlRow {
	my $product = shift;
	my $quantity = shift;
	my $lineTot = shift;
	return ("<tr><td><div class=\"checkbox\"><label><input type=\"checkbox\">$product</label></div></td><td>$quantity</td><td>\$$lineTot</td></tr>");
}

open(indexFile, "<index") or die("couldn't open index file");
&constrPricesHash();
close(indexFile);

open(modeFile, "<conf.txt") or die("couldn't open conf.txt");
my $mode = <modeFile>;
close(modeFile);
chomp($mode);
switch ($mode) {
	case "run"		{
		print "in run mode\n";
		&run();
	}
	case "display"	{
		print "in display mode\n";
		&printPrices();
	}
	else		{
		print "invalid configuration file\n";
	 }
}
