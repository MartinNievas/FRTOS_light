# Linterna frontal con diferentes modos de iluminación
La linterna cuenta con diferentes modos de iluminación. Es una versión simplificada inspirada en el modelo 
[NAO&reg;](https://www.petzl.com/US/en/Sport/PERFORMANCE-headlamps/NAO) de Petzl&reg;

## Modos de iluminación
* OFF (Default)
* ADAPTABLE
* AMPLIO
* CENTRADO
* AMPLIO + CENTRADO

##### Modo ADAPTABLE
La linterna regula la intensidad de los LED basada en la medición realizada por un fotodiodo. Los umbrales de cambio 
de intensidad controlan una máquina de estados, para evitar oscilaciones al cambiar entre modos.


## Circuito
La linterna se controla mediante una Arduino Pro-Mini y dos mosfet SMD (si2302) para controlar los LED. Cuenta con un botón en la placa 
para ir cambiando entre modos. 

## Alimentación
Utiliza dos bateras 18650 en serie. Esto  es así para alimentar la Arduino mediante el regulador provisto en la placa. 

## LEDs
La linterna utiliza dos LED. Uno de 3W para la iluminación centrada con un colimador de 16°, y un led de 5W para 
la iluminación amplia con un difusor de 60°

## Compilación y carga
El proyecto utiliza [platformio](http://platformio.org/). Para compilar y cargar en la Arduino hacer:
```
platofrmio run -t upload
```
