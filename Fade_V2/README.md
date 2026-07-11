# ESP32 PWM LED Dimmer - Version 2 (Smooth LED Fade)

## Overview

This project builds upon the basic PWM LED Dimmer by creating a **smooth fading effect**. Instead of displaying a fixed brightness level, the ESP32 gradually increases and decreases the LED's brightness by continuously changing the PWM duty cycle.

This project demonstrates how **PWM and loops** can be combined to create smooth animations, a technique widely used in embedded systems for LED effects, motor control, and user interface feedback.

---

## Objectives

- Learn how to dynamically change PWM duty cycle
- Create a smooth LED fading effect
- Understand the relationship between PWM values and brightness
- Explore how delay affects animation speed

---

## Components Used

- ESP32 Development Board
- LED
- 220 Ω Resistor
- Breadboard
- Jumper Wires

---

## Circuit Diagram

```text
GPIO 4 ---- 220Ω Resistor ---->|---- GND
```

---

## Working Principle

The ESP32 generates a PWM signal at a frequency of **5 kHz** with an **8-bit resolution**.

Instead of keeping the PWM value constant, the program gradually changes the duty cycle from **0 to 255**, making the LED slowly brighten. It then decreases the duty cycle from **255 back to 0**, causing the LED to dim smoothly.

This process repeats continuously, producing a fading or "breathing" LED effect.

---

## Program Flow

```text
Start

↓

Configure PWM

↓

Increase Brightness
(0 → 255)

↓

Decrease Brightness
(255 → 0)

↓

Repeat Forever
```

---

## Key Concepts Learned

- Pulse Width Modulation (PWM)
- Duty Cycle
- `for` Loops
- Incrementing and Decrementing Variables
- Smooth Software Animation
- Timing using `delay()`

---

## Code Highlights

- Configured PWM using the ESP32 LEDC peripheral
- Increased brightness gradually using:

```cpp
for (int brightness = 0; brightness <= 255; brightness++)
```

- Decreased brightness gradually using:

```cpp
for (int brightness = 255; brightness >= 0; brightness--)
```

- Updated LED brightness with:

```cpp
ledcWrite(LED_PIN, brightness);
```

- Controlled animation speed using:

```cpp
delay(10);
```

---

## Experiment

Try modifying the delay value:

```cpp
delay(1);
```

- Very fast fade

```cpp
delay(30);
```

- Slow fade

```cpp
delay(100);
```

- Very slow fade

You can also experiment with larger brightness steps:

```cpp
brightness += 5;
```

Observe how the LED transitions become less smooth compared to incrementing by 1.

---

## Learning Outcome

After completing this project, you should understand:

- How changing PWM values over time creates animations
- How `for` loops can be used to control hardware
- How delay affects animation speed
- How smooth LED fading is achieved using PWM

This project forms the basis for many real-world embedded applications such as breathing LEDs, motor speed ramps, dimmable lighting, and visual status indicators.

---

## Future Improvements

- Control brightness using push buttons
- Display brightness level on an OLED screen
- Implement non-blocking fading using `millis()`
- Add multiple fading patterns
- Create a customizable breathing LED effect

---

## Images

### Demo

![Fade](Images/Demo.gif)

## Author

**Danger Volt**

Learning Embedded Systems step by step using the ESP32, with each project introducing a new hardware or software concept while building toward more advanced embedded applications.