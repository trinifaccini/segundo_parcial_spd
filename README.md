# SEGUNDO PARCIAL SPD - TRINIDAD FACCINI - DIV D 

## Sistema de incendios con Tinkercard.

<img width="728" alt="image" src="https://github.com/trinifaccini/segundo_parcial_spd/assets/78211732/e9c067b3-25f2-4ad0-ab81-5856a6c54c6f">

## CONSIGNA

### OBJETIVO 

El objetivo de este proyecto es diseñar un sistema de incendio utilizando Arduino que pueda detectar cambios de temperatura y activar un servo motor en caso de detectar un incendio.

Además, se mostrará la temperatura actual y la estación del año en un display LCD.

### COMPONENTES NECESARIOS

Arduino UNO
Sensor de temperatura
Control remoto IR (Infrarrojo)
Display LCD (16x2 caracteres)
Servo motor
Cables y resistencias según sea necesario
Protoboard para realizar las conexiones
Dos leds.

### FUNCIONALIDAD REQUERIDA

Conexiones:

- Conecta el sensor de temperatura al pin analógico A0 de Arduino.
- Conecta el control remoto IR al pin digital 11 de Arduino.
- Conecta el display LCD utilizando los pines correspondientes de Arduino.
- Conecta el servo motor a uno de los pines PWM de Arduino (por ejemplo, pin 9).

## DESCRIPCION

El sistema de deteccion de incendios, segun lo que recibe el sensor de temperatura, se enciende con el control remoto y es posible cambiar la temperatura para variar las estaciones del año y que se muestren en el LCD, si pasa los 60 grados, se muestra la alerta de incendio. Ademas cuenta con un led verde que esta encendido mientras el sistema no detecta una temperatura que sobrepasa el limite, despues comienza a titilar el led rojo como si fuera una alarma.

## Diagrama esquematico

[Diagrama](https://github.com/trinifaccini/segundo_parcial_spd/blob/master/2DO_PARCIAL.pdf)

## Link al proyecto
[Tinkercard](https://www.tinkercad.com/things/l4OVtfaXYId-2do-parcial/editel?sharecode=pA9d3ynYB5pWP86FNbq1-eeV0V3HCdgNy893OjeqSKo)
