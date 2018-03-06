"""
TODO:
	-Add tax back calculator that can take the balance and tax from a receipt and store the tax rate to apply to.
	-Add a method for adding products that are priced per weight.

	Getting weird:
	-Add barcodes and maybe some method for looking up the product weight or something. I want a way to take the previously stored data and calculate how much a particular meals costs from it's ingredients
"""


indxFile = open("index", "r")

line = " "
options = {}

while len(line) > 0:
    line = indxFile.readline()
    if len(line) > 0:
        items = line.split(",")
        print items
        items[1] = items[1][:len(items[1]) - 1]
        print items
        options[items[0]] = float( items[1] )
        print options
else:
    indxFile.close()

def prompt():
    title = "Shopping List Generator"
    print " " + "-" * len(title) + " "
    print "|" + title + "|"
    print " " + "-" * len(title) + " \n"
    print "What would you like to do?"
    print "Add - Add an item"
    print "Display - show what can be bought"
    print "Save - save the current options list wtih any new items to the index file"
    print "Export - send shopping list to an HTML report file"
    print "Cart - Show current contents of the cart"
    print "Help - Shows this content"
    print "Exit - exits the program"
shoppingList = {}

#########     PROGRAM START      ########

prompt()

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
                    shoppingList[item]["quantity"] += int(addItem)
                else:
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
    elif userInput.lower() == "cart":
        runningTot = 0
        for item in shoppingList:
            print "%30s\t%1.2f X %d = $%1.2f" % (item, shoppingList[item]["price"], shoppingList[item]["quantity"], shoppingList[item]["price"] * shoppingList[item]["quantity"])
            runningTot += shoppingList[item]["price"] * shoppingList[item]["quantity"]
        print "Running Total: $" + str(runningTot)
    elif userInput.lower() == "updateItem":
        print "updateItem"
        pass
    elif userInput.lower() == "help":
        prompt()
    elif userInput.lower() == "save":
        saveFile = open("index", "w")
        for item in options:
            saveFile.write( item + "," + str( options[item] ) + "\n" )
        saveFile.close()
    elif userInput.lower() == "export":
        print "exporter"
        userInput = "exit"
    else:
        if userInput.lower() != "exit":
            print "option error... Try again"
else:
    print "Closing program"
    print options
