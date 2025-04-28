PasswordAnalyzer

Equipo de Trabajo
	•	George Meléndez
	•	Yaniel Molina

Descripción del Programa

PasswordAnalyzer es una aplicación en C++ diseñada para ayudar a los usuarios a evaluar la seguridad de sus contraseñas o generar nuevas contraseñas seguras automáticamente.

El programa analiza si una contraseña cumple con los siguientes requisitos:
	•	Tener al menos 12 caracteres de longitud.
	•	Contener letras mayúsculas.
	•	Contener letras minúsculas.
	•	Incluir números.
	•	Incluir símbolos especiales.
	•	No contener espacios.

Además, guarda un historial de las contraseñas analizadas o generadas en un archivo de texto llamado passwords.txt.

¿Qué problema resuelve?

Ayuda a los usuarios a mejorar la calidad de sus contraseñas, identificando debilidades específicas y promoviendo mejores prácticas de seguridad.

¿Cómo usarlo?
	1.	Compilar el archivo main.cpp en tu editor o IDE preferido.
	2.	Ejecutar el programa.
	3.	Seleccionar entre las opciones del menú:
	•	Analizar una contraseña ingresada manualmente.
	•	Generar una contraseña segura aleatoria.
	•	Ver el historial de contraseñas guardadas.
	•	Salir del programa.

Requisitos Técnicos
	•	Compilador C++ (como GCC o el compilador integrado de Visual Studio Community).
	•	Acceso a consola o terminal para correr el programa.
	•	Sistema operativo Windows para visualizar el historial usando notepad (o adaptar el comando si se usa otro sistema).

Librerías utilizadas
	•	<iostream> — Para entradas y salidas de texto.
	•	<fstream> — Para la creación y manejo de archivos.
	•	<string> — Para manipulación de cadenas.
	•	<cctype> — Para validar tipos de caracteres (mayúsculas, minúsculas, dígitos).
	•	<ctime> — Para la generación aleatoria de contraseñas.

Estructura del Proyecto
	•	main.cpp — Código fuente principal del programa.
	•	README.md — Documento descriptivo del proyecto (este archivo).

Version History
	•	v1.0 (28/abril/2025)
	•	Implementación inicial.
	•	Funciones básicas de análisis, generación y almacenamiento de contraseñas.



Licencia MIT
