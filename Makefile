project:	Control.o main.o Record.o RegionalFarmsReport.o AnimalTypeReport.o HorseSubRegReport.o ReportGenerator.o View.o
	g++ -o project Control.o  main.o Record.o RegionalFarmsReport.o AnimalTypeReport.o HorseSubRegReport.o ReportGenerator.o View.o

main.o:	main.cc AscBehaviour.h CompareBehaviour.h Control.h DescBehaviour.h Map.h Record.h RegionalFarmsReport.h AnimalTypeReport.h HorseSubRegReport.h ReportData.h ReportGenerator.h View.h
	g++ -c main.cc

Control.o:	Control.cc Control.h
	g++ -c Control.cc

Record.o:	Record.cc Record.h
	g++ -c Record.cc

RegionalFarmsReport.o:	RegionalFarmsReport.cc RegionalFarmsReport.h
	g++ -c RegionalFarmsReport.cc

AnimalTypeReport.o:	AnimalTypeReport.cc AnimalTypeReport.h
	g++ -c AnimalTypeReport.cc

HorseSubRegReport.o:	HorseSubRegReport.cc HorseSubRegReport.h
	g++ -c HorseSubRegReport.cc

ReportGenerator.o:	ReportGenerator.cc ReportGenerator.h
	g++ -c ReportGenerator.cc

View.o:	View.cc View.h
	g++ -c View.cc

clean:
	rm -f *.o project

valgrind:	project
	valgrind --leak-check=full ./project

