//
//  FT6236_t3.h
//
//  Created by Renaud Calmont on 24/11/2016.
//  MIT Licence.
//

#ifndef _FT6236_t3H_
#define _FT6236_t3H_

#ifdef __cplusplus
#include "Arduino.h"
#endif

#define FT6236_ADDR 0x38

enum {
    TouchIDLE = 0,
    TouchSTART = 1,
    //TouchMOVE = 2,
    //TouchEND = 3
};

struct TouchLocation {
  uint16_t x;
  uint16_t y;
};

struct TouchEvent {
    uint8_t type;
    TouchLocation location;
};

class FT6236_t3 {
public:
    FT6236_t3(uint8_t _ADDR, uint8_t _IRQ);
    void begin(void);

    TouchEvent currentTouchEvent();

protected:
    uint8_t _addr;
    uint8_t _irq;

private:
    void writeFT6236TouchRegister(uint8_t reg, uint8_t val);
    uint8_t readFT6236TouchLocation(TouchLocation *pLoc, uint8_t num);
    uint8_t attention;
    uint8_t oldAttention = 1;
    TouchLocation touchLocations[2];
    uint8_t readFT6236TouchRegister(uint8_t reg);
    uint8_t readFT6236TouchAddr(uint8_t regAddr, uint8_t *pBuf, uint8_t len);
};

#endif
