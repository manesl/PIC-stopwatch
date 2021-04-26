# PIC-stopwatch
A software based stopwatch which can count tenth of seconds, seconds, and minutes. The seconds are displayed on the LEDs in binary format.

Each second there will be defined number of clock cycles passing away. A timer on board is used to count the no of clock cycles. Thus if we know how many clock cycles passed away in a tenth of second or second, we can count those many using the timer. A timer when expired and resets, it generates an interrupt. The ISR routine can be useful to do some application. Our application for this project is to represent those seconds on the LEDs in binary format.

VideoURL: https://drive.google.com/file/d/1BMkr8b7bvxS2nrpqhM_tmkAU-K_6dm4k/view?usp=sharing
