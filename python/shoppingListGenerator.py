
indxFile = open("index", "r")

line = " "
options = {}

while len(line) > 0:
    line = indxFile.readline()
    if len(line) > 0:
        items = line.split(",")
        items[1] = items[1][:len(items[1]) - 1]
        options[items[0]] = float( items[1] )
else:
    indxFile.close()



shoppingList = {}

#########     PROGRAM START      ########


title = "Shopping List Generator"

print " " + "-" * len(title) + " "
print "|" + title + "|"
print " " + "-" * len(title) + " \n"
print "What would you like to do?"
print "Add - Add an item"
print "Display - show what can be bought"
print "Save - save the current options list wtih any new items to the index file"
print "Export - send shopping list to an HTML report file"
print "Exit - exits the program"

userInput = ""
while userInput.lower() != "exit":
    userInput = raw_input("@")
    if userInput.lower() == "add":
        print "Creating shopping list...\n"
        item = ""
        while item.lower != "done":
            item = raw_input("Item name: ")
            if item.lower() == "done":
                break
            elif item not in options.keys():
                addItem = raw_input("Item doesn't exist. Create it? y\\n\n")
                if addItem.lower() == "y":
                    options[item] = float(raw_input("How much does each cost? $"))
            if item in options.keys():
                addItem = raw_input("How many? ")
                if item in shoppingList.keys():
                    print "add to existing"
                    print shoppingList[item]["quantity"]
                    shoppingList[item]["quantity"] += int(addItem)
                    print shoppingList[item]["quantity"]
                else:
                    print "adding new to shopping list"
                    shoppingList[item] = {"price": options[item], "quantity": int(addItem)}
        else:
            print "price\tcount\titem"
            for each in shoppingList:
                print "$" + str(shoppingList[each]["price"]) + " ",
                print shoppingList[each]["quantity"] ,
                print " %30s" % (each)
    elif userInput.lower() == "display":
        for item in options:
            print "%30s" % (item),
            print "\t-\t%0.2f" % options[item]
    elif userInput.lower() == "save":
        print "saver"
    elif userInput.lower() == "export":
        print "exporter"
        userInput = "exit"
    else:
        if userInput.lower() != "exit":
            print "option error... Try again"
else:
    print "Closing program"
    print shoppingList
    total = 0.00
    for item in shoppingList:
        print "%30s  $%0.2f/ea  X%d  lineTot $%0.2f" % ( item, shoppingList[item]["price"], shoppingList[item]["quantity"], shoppingList[item]["price"] * shoppingList[item]["quantity"] )
        total += shoppingList[item]["price"] * shoppingList[item]["quantity"]
    print " " * 40 + "Total cost is $%0.2f" % total
