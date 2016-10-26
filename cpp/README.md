#Shopping List Generator

This is a program that stores whatever products you buy from the grocery store and allows you to create a shopping list that calculates approximately how much you'll spend

this program is best used with this workflow: [With tmux/make/g++ installed and in two windows mode with tmux]
 - (in one window) Run "$make display"
 - (switch to other window using tmux ctrl-b & o) Run "$make run"
 - Use the previous window to scroll through your purchase history to see what's available
 - Enter the name of the product you want to add to the list, and press Enter
 - Type in the quantity of that product you'd like, and press Enter
 - If entering a new item, simply type a new name, and enter "yes" when prompted if creating a new entry, and provide further info
 - When finished entering shopping list items, type "exit" and the program will cleanup and terminate, resulting in an html result file.
 - Move html file to some place accessible with a mobile browser at the grovery store. And check off the items as you gather them.



#Todo
 - [ ] Add ability to add new items in the form using jscrip/jquery
 - [ ] Find nice way to run on mobile
 - [ ] Streamline the display function to use less commands/typing
 - [ ] add an "edit entry" function for correcting entries in program
 - [ ] Add "appending/removing item" function in C++ as well as in javascript on the page for editing at the store
 - [ ] Add a "store" class to continuously update and average taxes from real data and to seperate different store apparent tax amount. Also helps manage different effects of different memberships
