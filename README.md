# yosefk-forth

A FORTH using C as an intermediate language, by Yossi Kreinin.

<http://yosefk.com/blog/c-as-an-intermediate-language.html>

This is a mirror of the files in the article linked above, so that you can
easily download them, run them, modify them, etc.

An error has also been fixed where two instances of `\n` in Yossi's article
rendered as `n` and broke the code.

## Usage

To run the example, if your environment supports static building:

```sh
$ sh script.sh
```

Otherwise, e.g. on OS X, try:

```sh
$ sh script-dynamic.sh
```

## Documentation

To understand how this works, read Yossi's article.
