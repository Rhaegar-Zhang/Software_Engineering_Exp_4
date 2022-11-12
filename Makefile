CC = g++
TARHET = judge_app
INCLUDE_PATH = ./code/h/
SRC_PATH = ./code/src/
OUT_PATH = ./code/outfile/
OBJ = $(OUT_PATH)main.o $(OUT_PATH)get_file_tree.o $(OUT_PATH)input.o $(OUT_PATH)execute.o $(OUT_PATH)judge.o

$(TARGET) : $(OBJ)     
	-$(CC) $(OBJ) -o $(TARGET) 

mian.o : $(SRC_PATH)main.cpp $(INCLUDE_PATH)get_file_tree.h $(INCLUDE_PATH)input.h $(INCLUDE_PATH)execute.h $(INCLUDE_PATH)judge.h
	-$(CC) -c $(SRC_PATH)main.cpp -o $(OUT_PATH)main.o

get_file_tree.o : $(SRC_PATH)get_file_tree.cpp $(INCLUDE_PATH)get_file_tree.h
	-$(CC) -c $(SRC_PATH)execute.cpp -o $(OUT_PATH)execute.o

input.o : $(SRC_PATH)input.cpp $(INCLUDE_PATH)input.h
	-$(CC) -c $(SRC_PATH)input.cpp -o $(OUT_PATH)input.o

execute.o : $(SRC_PATH)execute.cpp $(INCLUDE_PATH)execute.h
	-$(CC) -c $(SRC_PATH)execute.cpp -o $(OUT_PATH)execute.o

judge.o : $(SRC_PATH)judge.cpp $(INCLUDE_PATH)judge.h
	-$(CC) -c $(SRC_PATH)judge.cpp -o $(OUT_PATH)judge.o

.PHONY: clean  
clean:  
	rm -rf $(OBJ) ./code/output/

.PHONY: cleanall
	rm -rf $(OBJ) $(TARGET) ./code/outfile

.PHONY: play
play:
	$(OUT_PATH)$(TARGET)