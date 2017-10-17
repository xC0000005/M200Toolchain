/*
 * libmaple linker script for Malyan builds.
 *
 * Malyan has a bootloader in the first 8k, the program starts after that.
 */

/*
 * This pulls in the appropriate MEMORY declaration from the right
 * subdirectory of stm32/mem/ (the environment must call ld with the
 * right include directory flags to make this happen). Boards can also
 * use this file to use any of libmaple's memory-related hooks (like
 * where the heap should live).
 */
 MEMORY
 {
   ram (rwx) : ORIGIN = 0x20000000, LENGTH = 20K
   rom (rx)  : ORIGIN = 0x08002000, LENGTH = 120K
 }

/* Provide memory region aliases for common.inc */
REGION_ALIAS("REGION_TEXT", rom);
REGION_ALIAS("REGION_DATA", ram);
REGION_ALIAS("REGION_BSS", ram);
REGION_ALIAS("REGION_RODATA", rom);

/* Let common.inc handle the real work. */
INCLUDE common.inc
