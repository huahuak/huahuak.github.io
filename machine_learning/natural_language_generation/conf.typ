#let conf(
  title: none,
  authors: (),
  abstract: [],
  doc,
) = {
  // Set and show rules from before.
  // ...

  set page(margin: (x: 60pt))

  let fonts = (
      "Songti SC",
      "SimSun",
      "Times New Roman"
  )
  set text(font: fonts) 



  set align(center)
  text(17pt, title)

  let count = authors.len()
  let ncols = calc.min(count, 3)
  grid(
    columns: (1fr,) * ncols,
    row-gutter: 24pt,
    ..authors.map(author => [
      #author.name \
      #author.affiliation \
      #link("mailto:" + author.email)
    ]),
  )

  par(justify: false)[
    #set align(left)
    *摘#h(1em)要*:#abstract
  ]

  set align(left)
  set par(
    first-line-indent: 2em,
    justify: true,
  )

  set heading(numbering: "1.1.1")
  set text(size: 10pt)
  v(1em)

  columns(2, doc)

}