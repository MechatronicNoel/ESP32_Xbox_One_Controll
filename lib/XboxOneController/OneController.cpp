#include "Arduino.h"
#include "OneController.h"

struct OneController{
    uint16_t AxisLeftX;
    uint16_t AxisLeftY;
    uint16_t AxisRightX;
    uint16_t AxisRightY;
    uint16_t Triggers;
    int16_t Pov;
    uint16_t Buttons;
    uint16_t ButtonPressed;
} MyOne;

void GetValues(){
    char Buffer[256];
    char *Split_Buffer[256];
    char *ptr = NULL;
    byte index = 0;
    uint8_t size = 0;

    while ( Serial.available () ){
        size = Serial.readBytesUntil('\n',Buffer,sizeof(Buffer));
        Buffer[size] = 0;  

            
       ptr = strtok(Buffer,";");

            while ( ptr != NULL){
                Split_Buffer[index] = ptr;
                index++;
                ptr = strtok(NULL, ";");

            }
        
        /* Convertirmos los valores seriales a enteros y mapeamos para el rango permito por arduino
         si se requiere convertir a otro rango especificado lea mas sobre la funcion map*/
        MyOne.AxisLeftX = map ( atoi (Split_Buffer[0]),0, 65535,0,255); 
        MyOne.AxisLeftY = map ( atoi (Split_Buffer[1]),0, 65535,0,255);
        MyOne.AxisRightX = map ( atoi (Split_Buffer[2]),0, 65535,0,255);
        MyOne.AxisRightY = map ( atoi (Split_Buffer[3]),0, 65535,0,255);
        MyOne.Triggers = map ( atoi (Split_Buffer[4]),0, 65535,128,255);
        MyOne.Pov = atoi(Split_Buffer[5]);
        MyOne.Buttons = atoi(Split_Buffer[6]);
        MyOne.ButtonPressed = atoi(Split_Buffer[7]);
    }
      
}