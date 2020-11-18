#ifndef NVIC_h
#define NVIC_h



u8  EnableInterrupt (u8 ID);
u8  DisabelInterrupt (u8 ID);
u8 setPendingFlag   (u8 ID);
u8 clearPrndingFlag  (u8 ID);
u8 setPirority   (u8 interrupt ,u8 group ,u8 subgroup);

















#edndif