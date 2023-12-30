C Compiler's Optimization Flags

What is the value of using C compiler's optimization flags? What kind of trade-offs can you make?
- Running time vs. code size vs. memory usage vs. compile time
- Your compiler can take longer
to compile so your code can run faster
- Your compiler can take longer
to compile so your code size can be smaller 

What is the value of using -march=native flag when counting the number of 1 bits?
- C's compiler recognizes that you are trying to count the number of 1 bits in a number
and it uses the POPCNT assembly instruction to count the number of 1 bits
- when you don't use that flag, it becomes conservative and doesn't use the POPCNT assembly instruction
in case that instruction isn't compatible with your x86-64 architecture
- you can also use the __builtin_popcount(number) function

