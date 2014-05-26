CXX=g++
LDFLAGS=-ltesseract -llept
TARGET=tesseract
RM=rm -f

all:$(TARGET)

clean: 
	$(RM) $(TARGET)

