program som
implicit 

integer n, i, sum
double precision r

sum = 0
write (*,*) 'How many terms ?'
read *, n

do i = 1, n
sum = sum + i
r = sum / n
write (*,*) 'Sum = ', sum, ' and the average = ', r
enddo 
end