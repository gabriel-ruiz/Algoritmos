(define depth
	(lambda (arbol)
		(if (null? arbol)
			0
			(cond
				((eqv? arbol #f)
					0
				)
				((< (depth (car (cdr arbol))) (depth (car (cddr arbol))))
					(+ 1 (depth (car (cddr arbol))))
				)
				((> (depth (car (cdr arbol))) (depth (car (cddr arbol))))
					(+ 1 (depth (car (cdr arbol))))
				)
				((= (depth (car (cdr arbol))) (depth (car (cddr arbol))))
					(+ 1 (depth (car (cdr arbol))))				
				)
			)
		)
	)
)
