; Author:                     Shepard Berry
; Assignment Title:           P6_0, "Incremental Sum Average"
; Assignment Description:     Incremental Average
; Due Date:                   10-14-2022
; Date Created:               10-13-2022
; Date Last Modified:         10-13-2022

.586
.MODEL FLAT

INCLUDE io.h

.STACK 4096

.DATA
prompt1  BYTE    "How many grades to process?", 0
errMsg   BYTE    "INVALID NUMBER - enter nubmer > 0", 0
empty    BYTE    0
prompt2  BYTE    "Enter a test score:", 0
string   BYTE    30 DUP(?)
result   BYTE    "Incremental Sum and Average", 0
sum      BYTE    6 DUP(?), 0Dh, 0Ah
quot     BYTE    6 DUP(?), '.'
rem      BYTE    6 DUP (?), 0
numGrade WORD    ?

.CODE
_MainProc PROC
VALIDIN:
      input prompt1, string, 30    ; prompt user for num grades
      atow string                  ; convert num grades to numeric
      cmp ax, 0                    ; compare num grades to 0
      jg NEXT                      ; jump to NEXT if num grades > 0
      output errMsg, empty         ; output error message if num grades <= 0
      jmp VALIDIN                  ; jump to beginning of loop and repeat


NEXT: sub bx, bx                   ; init gradeCt to zero
      sub cx, cx                   ; init sum to zero
      mov numGrade, ax             ; mov num grades to mem

TOP:  input prompt2, string, 30    ; propmt user for test score
      atow string                  ; convert test score to numeric
      add cx, ax                   ; add grade to sum

      wtoa sum, cx                 ; convert sum to ASCII, store in mem

      mov ax, cx                   ; prepare numerator for divison

      inc bx                       ; prepare divisor for divison

      cwd                          ; converts word to dword for dividend

      idiv bx                      ; divide current sum by current count

      wtoa quot, ax                ; convert quot to ASCII, store in mem

      imul ax, dx, 100             ; mulitply rem by 100 store in ax

      cwd                          ; converts word to dword for dividend
      idiv bx                      ; calculate decimal equiv of rem
      wtoa rem, ax                 ; convert rem to ASCII, store in mem

      output result, sum           ; display sum and average

      cmp bx, numGrade             ; compare bx and num grade
      jl TOP                       ; jump to TOP if counter < numGrade

      sub eax, eax                 ; init return code to zero
      ret                          ; return to calling code
_MainProc ENDP
END