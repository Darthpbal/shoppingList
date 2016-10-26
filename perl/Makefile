run:confRun backup
	@echo calculating shopping list
	perl ./*pl

export:
	@echo exporting...
	mv -f ./*.html ~/Dropbox/

display:confDisp
	@echo displaying prices
	perl ./*pl
	cat options > tmpFile
	sort tmpFile > options
	rm tmpFile
	less options

readShList:
	less shoppingList.txt

confDisp:clean
	@echo putting program in display mode
	echo "display" > conf.txt
	cat conf.txt

confRun:cleanRun
	@echo putting program in run mode
	@echo "run" > conf.txt
	cat conf.txt

backup:
	cat index > indxBackup

clean:
	@echo cleaning
	rm -f ./*.txt ./*.html options
	clear

restore:
	cat indxBackup > index
	rm -f indxBackup
	cat index

cleanRun:
	@echo cleaning for main run...
	rm -f ./*txt
	clear
