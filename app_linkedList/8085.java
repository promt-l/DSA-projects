MVI A, 00H
STA 8093H
STA 8094H
STA 8095H
CALL FILL
CALL WASH
CALL DRAIN
HLT

FILL:
LDA 8093H
ADI 00H
JNZ Leave
CALL DELAY
MVI A, 01H
STA 8093H
Leave: RET

WASH:
LDA 8094H
ADI 00H
JNZ Leave1
LDA 8093H
ADI 00H
JZ Leave1
CALL DELAY
MVI A, 01H
STA 8094H
Leave1: RET

DRAIN:
LDA 8093H
ADI 00H
JZ Leave2
LDA 8094H
ADI 00H
JZ Leave2
LDA 8095H
ADI 00H
JNZ Leave2
CALL DELAY
MVI A, 01H
STA 8095H
Leave2: RET

DELAY:
    MVI B, 76H
Outer:
    MVI C, 0FFH
Inner:
    DCR C
    JNZ Inner
    DCR B
    JNZ Outer
    RET
