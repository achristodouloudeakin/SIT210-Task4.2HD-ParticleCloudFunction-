int led_ob = D7;     // The on-board LED
int led_red = A1;    // The Red LED
int led_yellow = A2; // The Yellow LED
int led_green = A5;  // The Green LED

void setup()
{
    pinMode(led_ob, OUTPUT);
    pinMode(led_red, OUTPUT);
    pinMode(led_yellow, OUTPUT);
    pinMode(led_green, OUTPUT);

    Particle.function("Red_Light", Red_Light_Toggle);
    Particle.function("Yellow_Light", Yellow_Light_Toggle);
    Particle.function("Green_Light", Green_Light_Toggle);
    Particle.function("Standart_Operation", Standard_Operation_Toggle);

    // Start with all LEDs off
    digitalWrite(led_ob, LOW);
    digitalWrite(led_red, LOW);
    digitalWrite(led_yellow, LOW);
    digitalWrite(led_green, LOW);
}

void LIGHT_ON(char led_x, int time_sec)
{
    digitalWrite(led_x, HIGH);
    delay(time_sec * 1000);
    digitalWrite(led_x, LOW);
}

int Red_Light_Toggle(String receiving_instruction)
{
    if (receiving_instruction == "on")
    {
        digitalWrite(led_red, HIGH);
        return 1;
    }
    else if (receiving_instruction == "off")
    {
        digitalWrite(led_red, LOW);
        return 0;
    }
    else
    {
        return -1;
    }
}

int Yellow_Light_Toggle(String receiving_instruction)
{
    if (receiving_instruction == "on")
    {
        digitalWrite(led_yellow, HIGH);
        return 1;
    }
    else if (receiving_instruction == "off")
    {
        digitalWrite(led_yellow, LOW);
        return 0;
    }
    else
    {
        return -1;
    }
}

int Green_Light_Toggle(String receiving_instruction)
{
    if (receiving_instruction == "on")
    {
        digitalWrite(led_green, HIGH);
        return 1;
    }
    else if (receiving_instruction == "off")
    {
        digitalWrite(led_green, LOW);
        return 0;
    }
    else
    {
        return -1;
    }
}

int Standard_Operation_Toggle(String receiving_instruction)
{
    if (receiving_instruction == "on")
    {
        digitalWrite(led_ob, HIGH);
        LIGHT_ON(led_red, 3);
        LIGHT_ON(led_yellow, 3);
        LIGHT_ON(led_green, 5);
        LIGHT_ON(led_yellow, 3);
        digitalWrite(led_ob, LOW);
        return 1;
    }
    else if (receiving_instruction == "off")
    {
        digitalWrite(led_ob, LOW);
        digitalWrite(led_red, LOW);
        digitalWrite(led_yellow, LOW);
        digitalWrite(led_green, LOW);
        return 0;
    }
    else
    {
        return -1;
    }
}
