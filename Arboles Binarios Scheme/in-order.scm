(define in-order
	(lambda (arbol)
		(if(null? arbol)
			arbol
			(cond
				((eqv? arbol #f)
					'()
				)
				(else
					(append (append (in-order (car (cdr arbol))) (list (car arbol))) (in-order (car (cddr arbol))))
				)
			)
		)
	)
)
