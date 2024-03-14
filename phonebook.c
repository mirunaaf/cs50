#include <stdio.h>
#include <cs50.h>

void formData()
{
    string name = get_string("Enter name: ");
    //int age = get_int("Enter age: ");
    int age;
    do {
        age = get_int("Enter age: ");
    }
    while (age < 18 || age > 165);

    string phoneNumber = get_string("Enter phoneNumber: ");
    //printf("Hello, %s\nYou are %i age old\nYour phone number is %s\n ", name, age, phoneNumber);
}

int main (void)
{
    formData();
}
