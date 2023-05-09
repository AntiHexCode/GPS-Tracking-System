#ifndef BIT_HELP
#define BIT_HELP

/* set specific bit of register to one */
#define SET_BIT(reg,bit_no) reg|=(1<<bit_no)

//////////////////////////////////////////////////

/* toogle  specific bit of register */
#define TOGGLE_BIT(reg,bit_no) reg^=(1<<bit_no)

/////////////////////////////////////////////////

/*clear specific bit of register */
#define CLEAR_BIT(reg,bit_no) reg&=~(1<<bit_no)

///////////////////////////////////////////////

/* set value for more than one bit */
#define SET_VALUE(reg,value) reg|=value

///////////////////////////////////////////

/*clear value for more than one bit*/
#define CLEAR_VALUE(reg,value) reg&=~value


/*clear value for more than one bit*/
#define TOGGLE_VALUE(reg,value) reg^=value




#endif
