; ---------------------------------------------------------------------
;
; Konwersja zdjecia kolorowego na zdjecie czarno - biale
; 24.10.2022 Filip Miera
; Informatyka SSI semestr 5 rok akademicki 2022 / 2023
; v.0.0.2
;
; Program napisany w asemblerze ma na celu przeksztalcenie
; kolorowego zdjecia na zdjecie czarno - biale.
; Wybrany przeze mnie sposob konwersji polega na pomnozeniu kazdego
; koloru  pojedynczego pixelu przez odpowiednie stale oraz dodanie ich do siebie.
; Do wyboru mialem :
; 1. pixel = (pixel.RED * 0.299 + pixel.GREEN * 0.587 + pixel.BLUE * 0.114)
; 2. pixel = (pixel.RED * 0.2126 + pixel.GREEN * 0.7152 + pixel.BLUE * 0.0722)
; 3. pixel = (pixel.RED * 0.2627 + pixel.GREEN * 0.6780 + pixel.BLUE * 0.0593)
; Jeszcze jedna mozliwoscia bylo wyliczenie sredniej z tych kolorow
; dla kazdego pixela :
; 4. pixel = ((pixel.RED + pixel.GREEN + pixel.BLUE) / 3)
;
; Roznice w wszytskich 4 sposobach byly praktycznie niezauwazalne,
; wiec wybralem losowo opcje 3.
;
; ---------------------------------------------------------------------



; tworzenie stalych ktore zostana uzyte do otrzymania odcieniu szarosci
.data
RED_MULTIPLIER real4 0.2627
GREEN_MULTIPLIER real4 0.6780
BLUE_MULTIPLIER real4 0.0593

.code
AsmConversion proc

movd xmm3, RED_MULTIPLIER
movd xmm4, GREEN_MULTIPLIER
movd xmm5, BLUE_MULTIPLIER
mulss xmm0, xmm3
mulss xmm1, xmm4
mulss xmm2, xmm5
addss xmm0, xmm1
addss xmm0, xmm2

ret
AsmConversion endp
end