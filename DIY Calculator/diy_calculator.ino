#include<Keypad.h>
#include<LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
long first = 0;
long second = 0;
double total = 0;
char custom_key;
int cursor_pos = 0; // Track cursor position

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
    {'1', '2', '3', '+'},
    {'4', '5', '6', '-'},
    {'7', '8', '9', '*'},
    {'c', '0', '=', '/'}
};
byte rowPins[ROWS] = {7, 6, 5, 4};
byte colPins[COLS] = {3, 2, 1, 0};
Keypad custom_keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Calculator");
    lcd.setCursor(0, 1);
    lcd.print("Enter numbers");
    delay(4000);
    lcd.clear();
    lcd.setCursor(0, 0);
    cursor_pos = 0;
}

void loop() {
    custom_key = custom_keypad.getKey();
    switch (custom_key) {
        case '0' ... '9':
            first = first * 10 + (custom_key - '0');
            lcd.print(custom_key); // Print the character, not the whole number
            cursor_pos++;
            break;
            
        case '+':
            first = (total != 0 ? total : first);
            lcd.print("+");
            cursor_pos++;
            second = secondNumber();
            total = first + second;
            lcd.setCursor(0, 1);
            lcd.print("Result: ");
            lcd.print(total);
            first = 0; 
            second = 0;
            break;
        
        case '-':
            first = (total != 0 ? total : first);
            lcd.print("-");
            cursor_pos++;
            second = secondNumber();
            total = first - second;
            lcd.setCursor(0, 1);
            lcd.print("Result: ");
            lcd.print(total);
            first = 0; 
            second = 0;
            break;
        
        case '*':
            first = (total != 0 ? total : first);
            lcd.print("*");
            cursor_pos++;
            second = secondNumber();
            total = first * second;
            lcd.setCursor(0, 1);
            lcd.print("Result: ");
            lcd.print(total);
            first = 0; 
            second = 0;
            break;
            
        case '/':
            first = (total != 0 ? total : first);
            lcd.print("/");
            cursor_pos++;
            second = secondNumber();
            if (second == 0) {
                lcd.setCursor(0, 1);
                lcd.print("Error: Div by 0");
            } else {
                total = (float)first / (float)second;
                lcd.setCursor(0, 1);
                lcd.print("Result: ");
                lcd.print(total);
            }
            first = 0; 
            second = 0;
            break;
            
        case 'c':
            total = 0;
            first = 0;
            second = 0;
            cursor_pos = 0;
            lcd.clear();
            lcd.setCursor(0, 0);
            break;
            
        default:
            break;
    }
}

long secondNumber() {
    while(1) {
        custom_key = custom_keypad.getKey();
        if (custom_key >= '0' && custom_key <= '9') {
            second = second * 10 + (custom_key - '0');
            lcd.print(custom_key); // Print the character directly
            cursor_pos++;
        }
        if (custom_key == '=') break;
    }
    return second;
}