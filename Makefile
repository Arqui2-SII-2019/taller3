PHONY: clean install

OPO=src/matriz44.o src/matrizFC.o src/main.o
OPB=bin/output

install:
		cd src/ && make
		
clean:
		rm $(OPB) $(OPO)