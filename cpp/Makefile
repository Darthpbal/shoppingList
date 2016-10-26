run:compileShopGen
	clear
	./shoppingListGenerator

compileShopGen:clean backup
	g++ shoppingListGenerator.cpp Shlist.cpp Helper.cpp -o shoppingListGenerator

backup:
	cat index > indxBackup

sort:
	sort index > tmpFile
	cat tmpFile > index
	rm -f tmpFile

clean:
	rm -f shoppingListGenerator displayOptions shoppingList.html options
	clear

exp:
	mv -f shoppingList.html ~/Dropbox/
