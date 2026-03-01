# DLL-Injection

First time trying DLL Injection. There are 3 files in this scenario:

- Main Program to act as the program being attacked
- Injector program to attack the Main program
- DLL
To inject the DLL, The injector must know the Process ID of the Main program, so: .\injector.exe PID And the attack is done!

The result will just open a Warning Window including a "Injection Successful!" text and an OK button!
