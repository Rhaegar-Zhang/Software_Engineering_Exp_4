TARGET = app
CXX = g++

SRC_DIR = ./code/src
INC_DIR = ./code/h
OUT_DIR = ./code/outfile

SRC_PATH = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_PATH = $(wildcard $(OUT_DIR)/*.o)
OBJ = main.o execute.o get_file_tree.o input.o judge.o

$(TARGET) : $(OBJ)
	@$(CXX) -o $(TARGET) $(OBJ_PATH)

$(OBJ):
	@$(CXX) -c $(SRC_PATH) -I $(INC_DIR)
	@$(shell if [ -d $(OUT_DIR) ];then echo "exit";else mkdir ./code/outfile;fi)
	@mv  ${OBJ} ${OUT_DIR}/

clean:
	@rm -rf $(TARGET) $(OUT_DIR)

all:
	@echo ${SRC_PATH}
	@echo ${OBJ}
	@echo ${OBJ_PATH}

play:
	@-./$(TARGET)