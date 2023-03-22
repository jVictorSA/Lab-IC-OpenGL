# --- Criado por José Fabiano
# -- Levemente modificado por João Victor Araujo

# --- COMPILA PROGRAMAS OPENGL ---
# --- COMO USAR? ---
# --- DIGITE: make programa CC=<ESPECIFIQUE SEU COMPILADOR> ---

# --- Para programas em C, use gcc ou clang
# --- Para programas em C++, use g++ ou clang++
# --- Por padrão o compilador usado será o g++, caso vc não especifique o parametro de entrada CC
# --- Por padrão o arquivo executável será de Linux. Para compilar para Windows, troque o argumento $(LINUX) por $(WINDOWS) nas regras de compilação

# --- EXEMPLOS DE USO:
# --- --- make picole CC=gcc (o arquivo fonte é um programa C - picole.c)
# --- --- make rosa_dos_ventos CC=clang++ (o arquivo fonte é um programa C++ - rosa_dos_ventos.cpp)

# --- COMPILADOR ---
CC = g++

# --- SISTEMA OPERACIONAL ---

# --- LIBS USADAS ---
XLIBS = -Wall -lGL -lGLU -lglut -lGLEW -lglfw -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor -lm

# --- ARQUIVO EXECUTÁVEL ---
LINUX = -o $@
WINDOWS = -o $@.exe

##### RULES #####
.SUFFIXES: .cpp .c

.cpp:
	$(CC) $< $(LINUX) $(XLIBS)
.c: 
	$(CC) $< $(LINUX) $(XLIBS)

##### TARGETS ######

clean:
	-rm *.o *~