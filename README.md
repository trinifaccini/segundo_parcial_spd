# SEGUNDO PARCIAL SPD - TRINIDAD FACCINI - DIV D 

## SISTEMA DE INCENDIOS CON TINKERCAD

<img width="728" alt="image" src="https://github.com/trinifaccini/segundo_parcial_spd/assets/78211732/e9c067b3-25f2-4ad0-ab81-5856a6c54c6f">

## CONSIGNA

### OBJETIVO 

El objetivo de este proyecto es diseñar un sistema de incendio utilizando Arduino que pueda detectar cambios de temperatura y activar un servo motor en caso de detectar un incendio.

Además, se mostrará la temperatura actual y la estación del año en un display LCD.

### COMPONENTES NECESARIOS

- Arduino UNO
- Sensor de temperatura
- Control remoto IR (Infrarrojo)
- Display LCD (16x2 caracteres)
- Servo motor
- Cables y resistencias según sea necesario
- Protoboard para realizar las conexiones
- Dos leds.

### FUNCIONALIDAD REQUERIDA

Conexiones:

- Conecta el sensor de temperatura al pin analógico A0 de Arduino.
- Conecta el control remoto IR al pin digital 11 de Arduino.
- Conecta el display LCD utilizando los pines correspondientes de Arduino.
- Conecta el servo motor a uno de los pines PWM de Arduino (por ejemplo, pin 9).

## DESCRIPCION

Este sistema de incendios se enciente mediante el boton de ON y OFF del control remoto infrarojo.
Una vez encendido se prenderá el led de color verde para indicar que está en funcionamiento.

El display LCD mostrará continuamente la temperatura actual que esta recibiendo el sensor de temperatura, acompañada tambien por el nombre de la estacion en la que nos encontramos. 
La estacion estará determinada por un rango previamente definido. 

Si el sensor de temperatura recibe una mayor a 60 grados, el display LCD dejará de mostrar la temperatura y la estacion y en cambio mostrará "ALERTA INCENDIO". Al mismo tiempo la luz del led rojo comenzará a titilar para altertar al usuario y el servo se moverá para simular una respuesta del sistema ante el incendio. 

## Diagrama esquematico

[Diagrama](https://github.com/trinifaccini/segundo_parcial_spd/blob/master/2DO_PARCIAL.pdf)

## Link al proyecto
[Tinkercard](https://www.tinkercad.com/things/l4OVtfaXYId-2do-parcial/editel?sharecode=pA9d3ynYB5pWP86FNbq1-eeV0V3HCdgNy893OjeqSKo)
