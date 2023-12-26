Left Shifting by N by multiplies the original number by 2 N times

For ex. 1 << 3 = 8
the work for it:
1) 1 in decimal converted to binary equals 1
2) 1 in binary left shifting 3 bits equals 1000
3) 1000 in binary equal 8 in decimal
4) This is the same as 1 * 2 * 2 * 2 = 1 * (2^3) = 8

Right Shifting by N by divides the original number by 2 N times and round downs to nearest integer

For ex. 7 >> 3 = 0
1) 7 in decimal converted to binary equals 111
2) 111 in binary right shifted 3 bits equals 000 = 0
3) This is the same as 7 * 1/2 * 1/2 * 1/2 = rounded to 0

For ex. 16 >> 4 = 1
1) 16 in decimal converted to binary equals 10000
2) 10000 in binary right shifted 4 bits equals 1 in binary which equals 1 in decimal
3) This is the same as 16 * 1/2 * 1/2 * 1/2 * 1/2 = 1