# Git Basics

A quick reference guide for everyday Git usage.

---

##  What is Git?

Git is a distributed version control system used to:

* Track changes in code
* Collaborate with others
* Maintain version history

---

##  Typical Workflow

git pull --rebase

git add .

git commit -m "message"

git push origin branch_name

---

##  Initial Setup

git config --global user.name "Your Name"

git config --global user.email "[your@email.com](mailto:your@email.com)"

git config --list

---

##  Initialize a Repository

git init

---

##  Tracking Files

Check status:
git status

Add files:

git add filename.c

git add .

---

##  Commit Changes

git commit -m "Your commit message"

---

##  Branching

Create branch:
git branch branch_name

Switch branch:
git checkout branch_name

Create and switch:
git checkout -b branch_name

List branches:
git branch

---

##  Merging

git checkout main
git merge branch_name

---

##  Remote Repositories

Add remote:
git remote add origin https://github.com/username/repo.git

Push:
git push origin main

Pull:
git pull origin main

Clone:
git clone https://github.com/username/repo.git

---

##  Pull vs Fetch

* git fetch → Downloads changes only
* git pull → Fetch + merge

---

##  Rebase

git pull --rebase

Keeps history clean and avoids unnecessary merge commits.

---

##  .gitignore

Example:

*.o

*.out

build/

---

##  Undo Changes

Unstage file:
git reset filename

Discard changes:
git checkout -- filename

Undo last commit (keep changes):
git reset --soft HEAD~1

---

##  View History

git log

git log --oneline

---

##  Common Issues

File still tracked after adding to .gitignore:
git rm --cached filename

Push rejected:
git pull --rebase
git push origin main

---

##  Best Practices

* Write clear commit messages
* Pull before pushing
* Use branches for features
* Avoid pushing directly to main
* Keep commits small

---


##  Summary

| Command    | Purpose         |
| ---------- | --------------- |
| git init   | Initialize repo |
| git add    | Stage changes   |
| git commit | Save changes    |
| git push   | Upload changes  |
| git pull   | Get changes     |
| git branch | Manage branches |

---

