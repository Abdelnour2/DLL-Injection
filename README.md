# DLL-Injection

### After learning about DLLs and DLL Injection, I wanted to try it. So I made 2 examples:
## Example 1:
It contains a main program to be attacked, an injector program that attacks the main program, and the DLL. To inject the main program, you need to run the injector and provide to it the Process ID of the main program (I made the main program to print its PID). Once the injection is done, a Warning Windows will pop up containing a "Injection Successfult!" text, and an OK button.

## Example 2:
This example a simulation of hacking a game! The main program prints the player health and coordinates! Again to inject the DLL you need to provide the PID to the injector. Once done, the player health and coordinate will change!
