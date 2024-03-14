#include <stdio.h>
#include<cs50.h>

bool valid_triangle (float x, float y, float z);
int main(void){
    // check for all positive sides
    float x = get_float("Side 1: ");
    float y = get_float("Side 2: ");
    float z = get_float("Side 3: ");

    bool is_triangle = valid_triangle(x, y, z);
    printf("%d\n", is_triangle);
}

bool valid_triangle(float x, float y, float z){
    if (x <= 0 || y <= 0 || z <= 0){
        return false;
    }

    // check sum of two sides is greater than third
    if(x + y <= z || x + z <=y || y + z <= x){
        return false;
    }
    return true;
}
