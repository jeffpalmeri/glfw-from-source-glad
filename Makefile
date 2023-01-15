main: main.c
	cc -o prog main.c gl.c -framework Cocoa -framework OpenGL -framework IOKit -lglfw3
