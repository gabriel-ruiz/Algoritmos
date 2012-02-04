(define minimum
	(lambda (arbol) 
		(if (eqv? (car (cdr arbol)) #f)
			arbol
			(minimum (car (cdr arbol)))
		)
	)
)
