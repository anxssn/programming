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
Your branch is up to date with 'origin/mybranch'.
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

17. **Проверка наличия двух веток на GitHub, пуш ветки master:**

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
1. **Переключаемся на ветку mybranch:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git switch mybranch

Switched to branch 'mybranch'
Your branch is up to date with 'origin/mybranch'.
```

2. **В файл sort.c добавляем функцию main(), в которой
будет объявлен массив из нескольких чисел и
вызвана функция сортировки для этого массива:**

```c
// sort.c 
#include <stdio.h>

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

int main() {
    int a[] = {4, 2, 0};
    int n = sizeof(a) / sizeof(a[0]);
    bubble_sort(a, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
       printf("%d ", a[i]);
    }
     printf("\n");
     return 0;
}
```
3. ***git diff* - анализ изменений:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git diff

diff --git a/laba9_git/sort.c b/laba9_git/sort.c
index 1f43862..2d4fa2f 100644
--- a/laba9_git/sort.c
+++ b/laba9_git/sort.c
@@ -1,11 +1,27 @@
 // sort.c
+#include <stdio.h>
+
 void bubbleSort(int arr[], int n) {
-    for (int i = 0; i < n - 1; i++) {
-        for (int j = 0; j < n - i - 1; j++) {
-            if (arr[j] > arr[j + 1]) {
+    for (int i = 0; i < n-1; i++)
+        for (int j = 0; j < n-i-1; j++)
+            if (arr[j] > arr[j+1]) {
                 int temp = arr[j];
                 arr[j] = arr[j+1];
                 arr[j+1] = temp;
             }
         }
     }
+}
+
+int main() {
+    int a[] = {4, 2, 0};
+    int n = sizeof(a)/sizeof(a[0]);
+
+    bubbleSort(a, n);
+
+    printf("Sorted array: ");
+    for (int i = 0; i < n; i++) {
+        printf("%d ", a[i]);
+    }
+    printf("\n");
+
+    return 0;
+
}
```
4. ***git diff --staged* - проверка индексированных изменений:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git diff --staged
```

5. **Добавляем в область staged файл sort.c**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git add sort.c
```

6. ***git diff* после индексации:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git diff
```
7. ***git diff --staged* после индексации:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git diff --staged

diff --git a/laba9_git/sort.c b/laba9_git/sort.c
index 1f43862..2d4fa2f 100644
--- a/laba9_git/sort.c
+++ b/laba9_git/sort.c
@@ -1,11 +1,27 @@
 // sort.c
+#include <stdio.h>
+
 void bubbleSort(int arr[], int n) {
-    for (int i = 0; i < n - 1; i++) {
-        for (int j = 0; j < n - i - 1; j++) {
-            if (arr[j] > arr[j + 1]) {
+    for (int i = 0; i < n-1; i++)
+        for (int j = 0; j < n-i-1; j++)
+            if (arr[j] > arr[j+1]) {
                 int temp = arr[j];
                 arr[j] = arr[j+1];
                 arr[j+1] = temp;
             }
         }
     }
+}
+
+int main() {
+    int a[] = {4, 2, 0};
+    int n = sizeof(a)/sizeof(a[0]);
+
+    bubbleSort(a, n);
+
+    printf("Sorted array: ");
+    for (int i = 0; i < n; i++) {
+        printf("%d ", a[i]);
+    }
+    printf("\n");
+
+    return 0;
+
}
```
8. **Удаляем число в массиве в sort.c**

9. ***git diff* после удаления:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git diff 

diff --git a/laba9_git/sort.c b/laba9_git/sort.c
index 2d4fa2f..0448801 100644
--- a/laba9_git/sort.c
+++ b/laba9_git/sort.c
@@ -12,7 +12,7 @@ void bubblesort(int arr[], int n) {
}

int main() {
    int a[] = {4, 2, 0};
    int a[] = {4, 0};
    int n = sizeof(a)/sizeof(a[0]);

    bubblesort(a, n);
```

10. ***git diff --staged* после удаления**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git diff --staged

diff --git a/laba9_git/sort.c b/laba9_git/sort.c
index 1f43862..2d4fa2f 100644
--- a/laba9_git/sort.c
+++ b/laba9_git/sort.c
@@ -1,11 +1,27 @@
+/ / sort.c
#include <stdio.h>
+
void bubbleSort(int arr[], int n) {
-    for (int i = 0; i < n - 1; i++) {
-        for (int j = 0; j < n - i - 1; j++) {
-             if (arr[j] > arr[j + 1]) {
+    for (int i = 0; i < n-1; i++)
+        for (int j = 0; j < n-i-1; j++)
+            if (arr[j] > arr[j+1]) {
                 int temp = arr[j];
-                 arr[j] = arr[j + 1];
-                 arr[j + 1] = temp;
+                 arr[j] = arr[j+1];
+                 arr[j+1] = temp;
              }
          }
}
+
+int main() {
+    int a[] = {4, 2, 0};
+    int n = sizeof(a)/sizeof(a[0]);
+
+    bubblesort(a, n);
+
+    printf("Sorted array: ");
+    for (int i = 0; i < n; i++)
+    printf("%d ", a[i]);
+
+    printf("\n");
+
+    return 0;
 }  
```

11. **Объяснение ситуации: В индексе находятся изменения с добавлением main() функции В рабочей директории есть дополнительное изменение (удаление числа 8) Git показывает разные diff для staged и unstaged изменений**

12. ***git status* - файл sort.c присутствует дважды в выводе:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git status

On branch mybranch
Your branch is up to date with 'origin/mybranch'.

Changes to be committed:
(use "git restore --staged <file>..." to unstage)
    modified:    sort.c

Changes not staged for commit:
(use "git add <file>..." to update what will be committed)
(use "git restore <file>..." to discard changes in working directory)
    modified:    sort.c
```

13. ***git restore --staged* sort.c - отмена индексации:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git restore --staged sort.c
```

14. **Проверка *git status* после отмены:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git status

On branch mybranch
Your branch is up to date with 'origin/mybranch'.

Changes not staged for commit:
(use "git add <file>..." to update what will be committed)
(use "git restore <file>..." to discard changes in working directory)
    modified: sort.c
```

15. **Индексация и коммит изменений:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git add sort.c

arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git commit -m "Добавлен массив"
[mybranch ba8543a] Добавлен массив

1 file changed, 22 insertions(+), 6 deletions(-)
```

16. **Просматриваем журнал (*git log*)**

17. **Добавляем в sort.c в main() printf(“hello git\n”);**

18. **Содержимое sort.c:**

```c
// sort.c 
#include <stdio.h>

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

int main() {
    int a[] = {4, 0};
    int n = sizeof(a) / sizeof(a[0]);
    bubble_sort(a, n);
    printf(“hello git\n”);
    for (int i = 0; i < n; i++) {
       printf("%d ", a[i]);
    }
     printf("\n");
     return 0;
}
```
19. ***git status* после добавления *printf:***

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git status

On branch mybranch
Your branch is ahead of 'origin/mybranch' by 1 commit.
(use "git push" to publish your local commits)

Changes not staged for commit:
(use "git add <file>..." to update what will be committed)
(use "git restore <file>..." to discard changes in working directory)
    modified:    sort.c

no changes added to commit (use "git add" and/or "git commit -a")
```

20. ***git restore sort.c* - отмена изменений:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git restore sort.c
```

21. **Проверка содержимого sort.c:**

```c
// sort.c 
#include <stdio.h>

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

int main() {
    int a[] = {4, 0};
    int n = sizeof(a) / sizeof(a[0]);
    bubble_sort(a, n);
    printf(“hello git\n”);
    for (int i = 0; i < n; i++) {
       printf("%d ", a[i]);
    }
     printf("\n");
     return 0;
}
```
22. **Проверка *git status:***

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git status

On branch mybranch
Your branch is ahead of 'origin/mybranch' by 1 commit.
    (use "git push" to publish your local commits)

nothing to commit, working tree clean
```

23. ***git push* - отправка ветки на удаленный репозиторий:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git push origin mybranch

Enumerating objects: 7, done.
Counting objects: 100% (7/7), done.
Delta compression using up to 12 threads
Compressing objects: 100% (4/4), done.
Writing objects: 100% (4/4), 667 bytes | 22.00 KiB/s, done.
Total 4 (delta 0), reused 0 (delta 0), pack-reused 0
To github.com:Erzaaa35/Programming-.git
    1254c29..ba8543a mybranch -> mybranch
```

## Работа с ветками и ff-merge:

1. **Создаем файл greeting.txt, индексируем его и коммитим с
сообщением “Add file greeting.txt”:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ touch greeting.txt
```

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git add greeting.txt
```

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git commit -m "Add file greeting.txt"

[main 5179373] Add file greeting.txt
   1 file changed, 0 insertions(+), 0 deletions(-)
   create mode 100644 laba9 git/greeting.txt
```
2. **Добавление слова "hello", индексация и коммит:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ echo “hello” > greeting.txt
```

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git add greeting.txt
```

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git commit -m "Add content to greeting.txt”

[mybranch e2@55cf] Add content to greeting.txt
1 file changed, 1 insertion(+)
```
3. **Создание ветки feature/uppercase:**
```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git checkout -b feature/uppercase

Switched to a new branch 'feature/uppercase'
```
4. **Проверяем на какой мы ветке:**

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git branch

*feature/uppercase
main
mybranch
```

5. **Проверка *git status:***

```
arrzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git status

On branch feature/uppercase

nothing to commit, working tree clean
```

6. **Редактирование greeting.txt в верхний регистр ("HELLO"):**

```
arzzz@Admin:/mnt/d/vs code/code/c/laba9_git$ echo "HELLO" > greeting.txt
```

7. **Добавляем файл greeting.txt и коммитим:**

```
arzzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git add greeting.txt

arzzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git commit -m "Отредактировали файл"

[feature/uppercase a9a3a41] Отредактировали файл
 1 file changed, 1 insertion(+), 1 deletion(-)
```

8. **Вывод *git branch:***

```
arzzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git branch

* feature/uppercase
  main
  mybranch
```
9. **Вывод *git log --oneline --graph –all:***

```
arzzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git log --oneline --graph --all

* a9a3a41 (HEAD -> feature/uppercase) Отредактировали файл
* 339d938 (main) Add content to greeting.txt
* 5179373 Add file greeting.txt
* 335c290 (origin/main) перенос
* 6ef90a8 Добавлен file2.txt
*   8d464ff (origin/mybranch, mybranch) Добавлен массив
*   bbaefd2 удаление
*   f406cb3 Перенос файлов
*   a6e0a8c Добавлен файл с командами
*   732740d Добавлен файл со своим именем
|/
* 568aadd lab9 -> lab9
```

10. **Переключаемся на главную ветку:**

```
arzzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git switch main

Switched to branch 'main'
Your branch is ahead of 'origin/main' by 2 commits.
  (use "git push" to publish your local commits)
```

11. ***cat* - проверка содержимого greeting.txt:**

```
arzzz@Admin:/mnt/d/vs code/code/c/laba9_git$ cat greeting.txt

hello
```
12. **Сравнение веток:**

```
arzzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git diff main feature/uppercase

diff --git a/laba9_git/greeting.txt b/laba9_git/greeting.txt
index ce01362..e427984 100644
--- a/laba9_git/greeting.txt
+++ b/laba9_git/greeting.txt
@@ -1 +1 @@
-hello
+HELLO
```

13. **Объединяем ветки:**

```
arzzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git merge feature/uppercase

Updating 339d938..a9a3a41
Fast-forward
 laba9_git/greeting.txt | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)
```

14. **cat - проверка содержимого после слияния:**

```
arzzz@Admin:/mnt/d/vs code/code/c/laba9_git$ cat greeting.txt

HELLO
```

15. **Удаление ветки feature/uppercase:**

```
arzzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git branch -d feature/uppercase

Deleted branch feature/uppercase (was a9a3a41).
```

16. **Слияние ветки mybranch в master:**

```
arzzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git merge mybranch

Merge made by the 'ort' strategy.
 laba9_git/README.md     | 18 +++++++++++++++---
 laba9_git/commands.txt  | 42 ++++++++++++++++++++++++++++++++++++++++++
 laba9_git/file1.txt     |  1 +
 laba9_git/sort.c        | 25 +++++++++++++++++--------
 4 files changed, 77 insertions(+), 9 deletions(-)
 create mode 100644 laba9_git/commands.txt
 create mode 100644 laba9_git/file1.txt
```

17. ***git log --oneline --graph --all* - анализ истории:**

```
arzzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git log --oneline --graph --all

*   1e93a42 (HEAD -> main) Merge branch 'mybranch' into master
|\
| * 8d464ff (origin/mybranch, mybranch) Добавлен массив
| * bbaefd2 удаление
| * f406cb3 Перенос файлов
| * a6e0a8c Добавлен файл с командами
| * 732740d Добавлен файл со своим именем
* | a9a3a41 Отредактировали файл
* | 339d938 Add content to greeting.txt
* | 5179373 Add file greeting.txt
* | 335c290 (origin/main) перенос
* | 6ef90a8 Добавлен file2.txt
|/
```

18. ***git push* - отправка изменений на удаленный репозиторий:**

```
arzzz@Admin:/mnt/d/vs code/code/c/laba9_git$ git push origin main

Enter passphrase for key '/home/arzzz/.ssh/id_ed25519':
Enumerating objects: 18, done.
Counting objects: 100% (18/18), done.
Delta compression using up to 12 threads
Compressing objects: 100% (12/12), done.
Writing objects: 100% (14/14), 1.46 KiB | 14.00 KiB/s, done.
Total 14 (delta 3), reused 0 (delta 0), pack-reused 0
remote: Resolving deltas: 100% (3/3), done.
To github.com:anxssn/programming.git
   335c290..1e93a42  main -> main
```

19. **Отчет отправлен**

## На оценку 5:
