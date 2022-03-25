#include <stdio.h>
#include <stdint.h>

int main(void)
{
	uint16_t value = 0xFFFF;
	printf("Original Value: %u\n", value);
	printf("Unsigned 16->Signed 16: %hd\n", (int16_t)value);
	printf("Unsinged 16->Unsigned 32: %u\n", (unsigned int)value);
	printf("Unsigned 16->Unsigned 8: %hu\n", (uint8_t)value);
	printf("Unsigned 16->Signed 32: %d\n", (int)value);
	int16_t svalue = -1;
	printf("Original Value: %d\n", svalue);
	printf("Signed 16->Unsinged 16: %u\n", (uint16_t)svalue);
	printf("Signed 16->Signed 32: %d\n", (signed int)svalue);
	printf("Signed 16->Signed 8: %d\n", (uint8_t)svalue);
	printf("Signed 16->Unsigned 32: %u\n", (unsigned int)svalue);
}