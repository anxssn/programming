# *Лабораторная работа № 9*

## На оценку 3:

1. **Используем *git status*, чтобы узнать на какой ветке мы находимся:**

```
arrzz@Admin:/mnt/d/vs code/code/c/lab9_git$ git status

On branch main
nothing to commit, working tree clean
```

2. **Используем *git log*, чтобы посмотреть историю коммитов:**

```
arrzz@Admin:/mnt/d/vs code/code/c/lab9_git$ git log

commit ee663117baf6bfeasd0f7d2c80d474e0bd3ae6a1 (HEAD -> main)
Author: anxsnn <arrzz1207@gmail.com>
Date:   Sun Dec 14 21:21:36 2025 +0700

    Добавлен README.md для лабораторной работы 9
```

3. **Создаем файл sort.c c функцией сортировки:**

```c
// sort.c
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```

4. **Проверяем *git status* после создания файла:**

```
arrzz@Admin:/mnt/d/vs code/code/c/lab9_git$ git status

On branch main

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        screenshots/
        sort.c

nothing added to commit but untracked files present (use "git add" to track)
```

5. **Добавляем файл в область *stage* - *git add*:**

```
arrzz@Admin:/mnt/d/vs code/code/c/lab9_git$ git add sort.c
```

6. **Проверяем *git status* после добавления:**

```
arrzz@Admin:/mnt/d/vs code/code/c/lab9_git$ git status

On branch main

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        new file:   sort.c

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        screenshots/
```

7. **Используем *git commit*, чтобы закоммитить файл в репозиторий:**

```
arrzz@Admin:/mnt/d/vs code/code/c/lab9_git$ git commit -m "добавлена функция сортировки"

[main 4de9195] добавлена функция сортировки
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 sort.c
arrzz@Admin:/mnt/d/vs code/code/c/lab9_git$ git status
On branch main

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        screenshots/

nothing added to commit but untracked files present (use "git add" to track)
```

8. **Проверяем *git status* после коммита:**

```
arrzz@Admin:/mnt/d/vs code/code/c/lab9_git$ git status

On branch main

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   sort.c

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        screenshots/

no changes added to commit (use "git add" and/or "git commit -a")
```

9. **Добавляем комментарий с любым текстом в этот же файл sort.c**




10. **Проверяем *git status* после добавления:**

```
arrzz@Admin:/mnt/d/vs code/code/c/lab9_git$ git status

On branch main

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   sort.c

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        screenshots/

no changes added to commit (use "git add" and/or "git commit -a")
```
11. **Добавляем изменения в файл sort.c - *git add*:**

```
arrzz@Admin:/mnt/d/vs code/code/c/lab9_git$ git add sort.c
```

12. ***git status* после добавления изменений:**

```
arrzz@Admin:/mnt/d/vs code/code/c/lab9_git$ git status

On branch main

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   sort.c

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        screenshots/
```

13. **Повторно изменяем файл sort.c (добавляем комментарий):**
14. **Используем *git commit*, чтобы закоммитить файл в репозиторий:**

```
arrzz@Admin:/mnt/d/vs code/code/c/lab9_git$ git commit -m "Добавлены комментарии в sort.c"

[main c20137] Добавлены комментарии в sort.c
 1 file changed, 12 insertions(+)
```

15. **Проверяем как выглядит *git status* и *git log*:**

```
arrzz@Admin:/mnt/d/vs code/code/c/lab9_git$ git status

On branch main

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   sort.c

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        screenshots/

no changes added to commit (use "git add" and/or "git commit -a")
```

```
arrzz@Admin:/mnt/d/vs code/code/c/lab9_git$ git log --oneline --graph

* c20137 (HEAD -> main) Добавлены комментарии в sort.c
* 4de9195 Добавлена функция сортировки
* ee66311 Добавлен README.md для лабораторной работы 9
```

16. **Добавляем в область *stage* и коммитим последнее изменение:**

```
arrzz@Admin:/mnt/d/vs code/code/c/lab9_git$ git add sort.c

arrzz@Admin:/mnt/d/vs code/code/c/lab9_git$ git commit -m "Финальное изменение в sort.c"

[main e8742f5] Финальное изменение в sort.c
 1 file changed, 1 insertion(+), 1 deletion(-)
```

17. **Используем *git push* и пушим на удаленный репо**



## Работа с ветками:

1. **Командой *git branch mybranch (или git checkout -b mybranch)* создаем новую ветку с именем mybranch:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git branch mybranch
```

2. **Используем  *git branch*, чтобы увидеть новую созданную ветку:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git branch

* main
  mybranch
```
+ ***main** — звездочка указывает, что мы сейчас находимся на ветке main.

3.  **Командой *git switch mybranch (или git checkout mybranch)* переключаемся на новую ветку:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git switch mybranch

M       laba9_git/README.md
Switched to branch 'mybranch'
```

4. **Проверяем *git status* при переключении веток:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git status

On branch mybranch

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   README.md

no changes added to commit (use "git add" and/or "git commit -a")
```

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git status
On branch main
Your branch is up to date with 'origin/main'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        modified:   README.md

no changes added to commit (use "git add" and/or "git commit -a")
```

+ ***При переключении между ветками git status меняет только название текущей ветки (On branch main → On branch mybranch), но оставляет сообщение об одних и тех же незакоммиченных изменениях, потому что они ещё не принадлежат ни одной ветке.***

5. **Убеждаемся, что мы находимся на своей ветке mybranch:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git branch

  main
*mybranch
```

6. **Создаем файл с именем file1.txt и своим именем:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ echo "Аня" > file1.txt
```

7. **Добавляем файл и коммитим это изменение:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git add file1.txt
```

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git commit -m "Добавлен файл со своим именем"

[mybranch 732740d] Добавлен файл со своим именем
 1 file changed, 1 insertion(+)
 create mode 100644 file1.txt
 ```

 8. **Используем *git log --oneline --graph*, чтобы увидеть, что наша ветка указывает на новый коммит:**

 ```
 arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git log --oneline --graph

* 732740d (HEAD -> mybranch) Добавлен файл со своим именем
* 568aadd (origin/main, main) lab9 -> laba9
* 2563ca7 rm screen
* d102ebc (origin/fix_main, main) Финальное изменение в sort.c
* c4a8217 Добавлены комментарии в sort.c
* d3029b9 Добавлена функция сортировки
* 4541dd6 screen
* 3b782bc Очистка репозитория
* fe3b9da kfkfk
* 4cba098 kfkfk
* 1df645b first_commit
* f1a5f3a Merge branch 'main' of github.com:anxsnn/programming
```

9. **Возвращаемся к ветке с именем master:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git switch main

Switched to branch 'main'
Your branch is up to date with 'origin/main'.
```

10. ***git log --oneline --graph* - проверяем изменения**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git log --oneline --graph

* 568aadd (HEAD -> main, origin/main) lab9 -> laba9
* cb3b4bf rm screen
* 2563ca7 git pull
* d102ebc (origin/fix_main) Финальное изменение в sort.c
* c4a8217 Добавлены комментарии в sort.c
* d3029b9 Добавлена функция сортировки
* 4541dd6 screen
* 3b782bc Очистка репозитория
* fe3b9da kfkfk
* 4cba098 kfkfk
* 1df645b first_commit
* f1a5f3a Merge branch 'main' of github.com:anxsnn/programming
|\
| * 9ad065f Create README.md
* 4e12ef5 Init
```
+ **После переключения на main, команда *git log --oneline --graph* перестаёт показывать коммиты из mybranch, потому что они не входят в историю main**


11. **Создаем новый файл с именем file2.txt и коммитим его:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ touch file2.txt
```

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git add file2.txt
```

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git commit -m "Добавлен file2.txt"

[main 6ef90a8] Добавлен file2.txt
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 file2.txt
 ```

 12. **Используем *git log --oneline --graph --all*, чтобы увидеть, что наша ветка указывает на новый коммит, и что теперь у двух веток разные коммиты:**

 ```
 arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git log --oneline --graph --all

* 6ef90a8 (HEAD -> main) Добавлен file2.txt
* 732740d (mybranch) Добавлен файл со своим именем
* 568aadd (origin/main, main) lab9 -> laba9
* cb3b4bf rm screen
* 2563ca7 git pull
* d102ebc (origin/fix_main) Финальное изменение в sort.c
* c4a8217 Добавлены комментарии в sort.c
* d3029b9 Добавлена функция сортировки
* 4541dd6 screen
* 3b782bc Очистка репозитория
* fe3b9da kfkfk
* 4cba098 kfkfk
* 1df645b first_commit
* f1a5f3a Merge branch 'main' of github.com:anxsnn/programming
|\
| * 9ad065f Create README.md
* 4e12ef5 Init
```

13. **Переключаемся на ветку mybranch:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git switch mybranch

Switched to branch 'mybranch'
```

14. **Проверяем, что наш file2.txt пропал**

15. **Используем *git diff mybranch main*, чтобы увидеть разницу между
двумя ветками:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git diff mybranch main

diff --git a/file1.txt b/file1.txt
deleted file mode 100644
index a73a6ce..0000000
--- a/file1.txt
+++ /dev/null
@@ -1,0 +0,0 @@
-Aня
diff --git a/file2.txt b/file2.txt
new file mode 100644
index 0000000..e69de29
```

16. **Добавляем текстовый документ с командами в ветку mybranch.
Закоммитим и запушим на удаленный репо ветку mybranch (*git push -u
origin mybranch*):**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ nano commands.txt
```
```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git add commands.txt
```

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git commit -m "добавлен файл с командами"

[mybranch a6e0a8c] добавлен файл с командами
 1 file changed, 42 insertions(+)
 create mode 100644 commands.txt
 ```

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git push -u origin mybranch

Enumerating objects: 7, done.
Counting objects: 100% (7/7), done.
Delta compression using up to 12 threads
Compressing objects: 100% (5/5), done.
Writing objects: 100% (6/6), 1.13 KiB | 35.00 KiB/s, done.
Total 6 (delta 1), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (1/1), done.
remote: Create a pull request for 'mybranch' on GitHub by visiting:
remote:      https://github.com/anxsnn/programming/pull/new/mybranch
To github.com:anxsnn/programming.git
 * [new branch]      mybranch -> mybranch
branch 'mybranch' set up to track 'origin/mybranch'.
```

17. **Проверка наличия двух веток на GitHub, пуш ветки master**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git push origin main

Enumerating objects: 4, done.
Counting objects: 100% (4/4), done.
Delta compression using up to 12 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (3/3), 332 bytes | 14.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
To github.com:anxsnn/programming.git
   568aadd..6ef90a8  main -> main
```


## На оценку 4: