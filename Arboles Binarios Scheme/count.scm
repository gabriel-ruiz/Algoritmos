(define count
	(lambda (arbol)
		(if(null? arbol)
			0
			(cond
				((eqv? arbol #f)
					0
				)
				(else (+ 1 (+ (count (car (cdr arbol))) (count (car (cddr arbol))) )))
			)			
		)
	)
)
