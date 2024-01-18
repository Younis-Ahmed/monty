		; a bf what adds x + y = z while z is less than 10
,       ; read nums & store it in p1
>       ; move pointer to p2 (second byte)
,       ; read character and store it in p2
[       ; enter loop
<       ; move to p1
+       ; p1++
>       ; move to p2
-       ; p2--
]       ; exit the loop when last cell is empty
<       ; go back to p1
------------------------------------------------ ; subtract 48
				(like subtracting '0')
.       ; print p1
