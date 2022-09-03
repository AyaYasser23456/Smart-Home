/*
 * BitMath.h
 *
 * Created: 6/1/2022 3:52:19 PM
 *  Author: Ahmed Hesham
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

#define	SetBit(Reg,BitNo)		(Reg |= (1<<BitNo))
#define	ClrBit(Reg,BitNo)		(Reg &= (~(1<<BitNo)))
#define TogBit(Reg,BitNo)		(Reg ^= (1<<BitNo))
#define GetBit(Reg,BitNo)		(1   &  (Reg>>BitNo))



#endif /* BITMATH_H_ */