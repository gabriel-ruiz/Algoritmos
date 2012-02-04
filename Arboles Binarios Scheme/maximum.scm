(define maximum
	(lambda (arbol) 
		(if (eqv? (car (cddr arbol)) #f)
			arbol
			(maximum (car (cddr arbol)))
		)
	)
)
