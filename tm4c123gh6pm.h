// Macros
// System Control Registers (SYSCTL)
#define SYSCTL_RCGCGPIO_R        (*((volatile char *)0x400FE608))
#define SYSCTL_PRGPIO_R          (*((volatile char *)0x400FEA08))

// Constants
#define UNLOCK_KEY                         0x4C4F434B
#define CLOCK                               16000000
