#ifndef _MACROS_H_
#define _MACROS_H_

#define DIO_SET_BIT(REG, BIT) ((REG) |= (1 << (BIT)))
#define DIO_CLEAR_BIT(REG, BIT) ((REG) &= ~(1 << (BIT)))
#define DIO_TOGGLE_BIT(REG, BIT) ((REG) ^= (1 << (BIT)))

#endif