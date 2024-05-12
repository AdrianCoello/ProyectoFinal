# Como instalar el compilador (necesario para windows)

En esta parte se hara una explicacion paso a paso de como instalar un compilador de c++ para visual studio code.

## Buscar en Google: "https://www.msys2.org/"
Aquí hay una guía en la que se explican los pasos para instalar el compilador.
Primero debemos descargar este instalador:
![](https://github.com/AdrianCoello/ProyectoFinal/blob/main/Instalacion_Compilador/1.jpg.jpeg)
## Abrir el instalador descargado
Hay que mantener la direccion donde se descargará el archivo
![](https://github.com/AdrianCoello/ProyectoFinal/blob/main/Instalacion_Compilador/2.jpg.jpeg)
## Ver si faltan actualizaciones 
Aparecera una panatalla negra en la que primero se necesita escribir "$ pacman -Syu" y apretar la tecla ENTER. Esta funciona para actualizar los programas.
![](https://github.com/AdrianCoello/ProyectoFinal/blob/main/Instalacion_Compilador/3.jpg.jpeg)
En esta parte presionamos la tecla "y" y ENTER para continuar.
![](https://github.com/AdrianCoello/ProyectoFinal/blob/main/Instalacion_Compilador/4.jpg.jpeg)
## Actualizar los programas
Hay que cerrar la consola (la pantalla negra) y volver a abrir la aplicaion MSYS MSYS, nos volvera a salir la consola y hay que escribir "$ pacman -Su". En esta parte presionamos la tecla "y" y ENTER para continuar.
## Descargar los programas
Hay que escribir "$ pacman -S --needed base-devel mingw-w64-x86_64-toolchain" y luego ENTER
![](https://github.com/AdrianCoello/ProyectoFinal/blob/main/Instalacion_Compilador/5.jpg.jpeg)
En esa pantalla solo debemos presionar ENTER para descargar todos los programas del compilador y luego "y" para continuar.
## Conectar con el Path
Hay que entrar a las variables de entorno del sistema. y en la siguiente parte entrar a variables de entorno
![](https://github.com/AdrianCoello/ProyectoFinal/blob/main/Instalacion_Compilador/6.jpg.jpeg) 
Entrar a la parte de "Path" 
![](https://github.com/AdrianCoello/ProyectoFinal/blob/main/Instalacion_Compilador/7.jpg.jpeg) 
![](https://github.com/AdrianCoello/ProyectoFinal/blob/main/Instalacion_Compilador/8.jpg.jpeg) 
Apretamos el boton de new y escribimos la dirreccion "C:\msys64\mingw64\bin" y le damos a "ok".
## Comprobar
Para saber que la coneccion esta bien hecha, abrimos la consola cmd en nuestra computadoras y escribimos el siguiente comando: "g++ --version". y deberia aparecernos lo siguiente.
![](https://github.com/AdrianCoello/ProyectoFinal/blob/main/Instalacion_Compilador/9.jpg.jpeg) 
## Utilizar el compilador
Entramos a visual studio code, escribimos codigo y nos vamos a la parte de terminal, lanzamos un nueva terminal, nos aparecera la siguiente consola, en la que debemos escribir "g++ nombreDelArchivo.cpp -o nombreDelArchivo", esto hara que en la misma carpeta donde esta el archivo se cree un ejecutable con el mismo nombre, entolnces ahi solo tendremos que escribir: "./nombreDelArchivo.exe" y asi ya podriamos compilar nuestro codigo de c++.
#### Si necesita ayuda
En el siguiente video, se muestra todo este proceso explicado al detalle y paso a paso: "https://youtu.be/v3ENcQpoA5A?si=VIzdFT5bssVywTeT"
