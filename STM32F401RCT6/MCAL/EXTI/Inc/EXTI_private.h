/*
 * EXTI_private.h
 *
 *  Created on: Jun 1, 2024
 *      Author: Amr Salhen
 */

#ifndef MCAL_EXTI_INC_EXTI_PRIVATE_H_
#define MCAL_EXTI_INC_EXTI_PRIVATE_H_

#define		RAISED			1

#define		EXTI5_FLAG		((EXTI->PR>>5)&1)
#define     EXTI6_FLAG		((EXTI->PR>>6)&1)
#define     EXTI7_FLAG		((EXTI->PR>>7)&1)
#define     EXTI8_FLAG		((EXTI->PR>>8)&1)
#define     EXTI9_FLAG		((EXTI->PR>>9)&1)
#define     EXTI10_FLAG		((EXTI->PR>>10)&1)
#define     EXTI11_FLAG		((EXTI->PR>>11)&1)
#define     EXTI12_FLAG		((EXTI->PR>>12)&1)
#define     EXTI13_FLAG		((EXTI->PR>>13)&1)
#define     EXTI14_FLAG		((EXTI->PR>>14)&1)
#define     EXTI15_FLAG		((EXTI->PR>>15)&1)


#endif /* MCAL_EXTI_INC_EXTI_PRIVATE_H_ */
