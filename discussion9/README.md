CS429 Git Demo
==============

# Thanks to former TAs Yaswin Veluguleti and Sai Kiran Maddela for writing this!

## Getting Started
1. Clone this repo using `> git clone <this Repo URL>`
1. Use `ls - a` uto see `.git` directory
    - Files beginning with `.` are called "hidden files". These need the `-a` flag (`--all`) to see them.
1. These demos follow each other. Do not try to reset between them. If you mess up, delete the repo and try again from the start.
1. Any lines starting with `>` are showing what was given to the shell. You do not have to type them.
1. Any lines starting with `>>` should be run in the terminal. If you see them, actually type them out during the demo.
1. If you see this: `<description>`, replace that block with what's supposed to be there. Do NOT type that out literally.
1. There are SVGs in this markdown that Github might not show. Try copying this file into VSCode and right-click previewing the file.
---------------------------------------------------------------------------------

## Exploring the Data Models
Blobs (files), Trees (folders), and Commits (snapshots) can all be found in `.git/objects/`. They are organized by their hashid with the first two digits being a folder.<br>
For example:
- Object with hashid `367b42d08...` will be in `./git/objects/36/7b42d08...`
- Object with hashid `59ac22188...` will be in `./git/objects/59/ac22188...`
- Object with hashid `36beefbee...` will be in `./git/objects/36/beefbee...`

Use `> git cat-file -p <hashid>` to see information about the object. If done on a commit object, it should look something like this:
```
> git cat-file -p 367b           
tree 543b9bebdc6bd5c4b22136034a95dd097a57d3dd
author <author-info>
committer <committer-info>

Initial commit
```

### Demo
1. `>> touch test.txt`
1. `>> git add test.txt`
1. `>> git commit -m "Models 1"` 
1. Look at commit output and note the commit's hashid
1. Try finding the commit information for the most recent commit
1. Identify the hashid of the tree and the blob that was just committed
1. With the blob hashid, print out the contents of `test.txt` (should be empty)
1. **<u>Task 1</u>**: Try to make a tree diagram of the objects.
1. `>> echo "first test change" > test.txt`
1. `>> git add test.txt`
1. `>> git commit -m "Models 2"`
1. **<u>Task 2</u>**: Try to make a new tree diagram of the objects



### Task Answers
#### Task 1:
<svg width="640" height="480" xmlns="http://www.w3.org/2000/svg" xmlns:svg="http://www.w3.org/2000/svg">
 <!-- Created with SVG-edit - http://svg-edit.googlecode.com/ -->

 <g>
  <title>Layer 1</title>
  <rect stroke="#000000" id="svg_4" height="85" width="116.00001" y="33" x="31" stroke-width="5" fill="#FF0000"/>
  <rect id="svg_7" height="85" width="114" y="33" x="457" stroke-width="5" stroke="#000000" fill="#FF0000"/>
  <text xml:space="preserve" text-anchor="middle" font-family="serif" font-size="24" id="svg_9" y="107" x="519" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="0" stroke="#000000" fill="#000000">Commit</text>
  <text id="svg_10" xml:space="preserve" text-anchor="middle" font-family="serif" font-size="24" y="59.5" x="89.83594" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="0" stroke="#000000" fill="#000000">Commit</text>
  <text id="svg_11" xml:space="preserve" text-anchor="middle" font-family="serif" font-size="24" y="106.5" x="90.83594" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="0" stroke="#000000" fill="#000000">Initial</text>
  <text id="svg_12" xml:space="preserve" text-anchor="middle" font-family="serif" font-size="24" y="59.5" x="517.83594" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="0" stroke="#000000" fill="#000000">Models 1</text>
  <rect id="svg_16" stroke="#000000" height="85" width="116.00001" y="156" x="104" stroke-width="5" fill="#FF0000"/>
  <rect id="svg_17" stroke="#000000" height="85" width="116.00001" y="156" x="331" stroke-width="5" fill="#FF0000"/>
  <rect id="svg_18" stroke="#000000" height="85" width="116.00001" y="274" x="102" stroke-width="5" fill="#FF0000"/>
  <rect id="svg_19" stroke="#000000" height="85" width="116.00001" y="272" x="333" stroke-width="5" fill="#FF0000"/>
  <text xml:space="preserve" text-anchor="middle" font-family="serif" font-size="24" id="svg_20" y="180" x="162" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="0" stroke="#000000" fill="#000000">Tree</text>
  <text id="svg_21" xml:space="preserve" text-anchor="middle" font-family="serif" font-size="24" y="181.5" x="391.82813" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="0" stroke="#000000" fill="#000000">Tree</text>
  <text style="cursor: move;" id="svg_22" xml:space="preserve" text-anchor="middle" font-family="serif" font-size="24" y="298.5" x="389.82813" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="0" stroke="#000000" fill="#000000">Blob</text>
  <text style="cursor: move;" id="svg_23" xml:space="preserve" text-anchor="middle" font-family="serif" font-size="24" y="297.5" x="153.82813" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="0" stroke="#000000" fill="#000000">Blob</text>
  <text xml:space="preserve" text-anchor="middle" font-family="serif" font-size="24" id="svg_24" y="230" x="162" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="0" stroke="#000000" fill="#000000">&lt;hash a&gt;</text>
  <text style="cursor: move;" id="svg_25" xml:space="preserve" text-anchor="middle" font-family="serif" font-size="24" y="228.5" x="389.76563" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="0" stroke="#000000" fill="#000000">&lt;hash b&gt;</text>
  <text style="cursor: move;" id="svg_26" xml:space="preserve" text-anchor="middle" font-family="serif" font-size="24" y="347.5" x="160.76563" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="0" stroke="#000000" fill="#000000">readme.md</text>
  <text style="cursor: move;" id="svg_27" xml:space="preserve" text-anchor="middle" font-family="serif" font-size="24" y="347.5" x="393" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="0" stroke="#000000" fill="#000000">test.txt</text>
  <text xml:space="preserve" text-anchor="middle" font-family="serif" font-size="24" id="svg_28" y="425" x="161" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="0" stroke="#000000" fill="#000000">&lt;readme content&gt;</text>
  <text style="cursor: move;" id="svg_29" xml:space="preserve" text-anchor="middle" font-family="serif" font-size="24" y="424.5" x="394.76563" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="0" stroke="#000000" fill="#000000">&lt;empty&gt;</text>
  <line id="svg_30" y2="86" x2="145" y1="82" x1="455" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="5" stroke="#000000" fill="none"/>
  <line id="svg_31" y2="157" x2="393" y1="118" x1="512" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="5" stroke="#000000" fill="none"/>
  <line id="svg_32" y2="154" x2="162" y1="117" x1="86" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="5" stroke="#000000" fill="none"/>
  <line id="svg_33" y2="277" x2="159" y1="241" x1="157" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="5" stroke="#000000" fill="none"/>
  <line id="svg_34" y2="274" x2="217" y1="241" x1="388" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="5" stroke="#000000" fill="none"/>
  <line id="svg_35" y2="410" x2="157" y1="361" x1="157" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="5" stroke="#000000" fill="none"/>
  <line id="svg_36" y2="271" x2="391" y1="241" x1="391" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="5" stroke="#000000" fill="none"/>
  <line id="svg_37" y2="412" x2="398" y1="359" x1="398" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="5" stroke="#000000" fill="none"/>
 </g>
</svg>

#### Task 2:
<svg width="800" height="480" xmlns="http://www.w3.org/2000/svg" xmlns:svg="http://www.w3.org/2000/svg">
 <!-- Created with SVG-edit - http://svg-edit.googlecode.com/ -->
 <g>
  <title>Layer 1</title>
  <rect fill="#FF0000" stroke-width="5" x="31" y="33" width="116.00001" height="85" id="svg_4" stroke="#000000"/>
  <rect fill="#FF0000" stroke="#000000" stroke-width="5" x="332" y="30" width="114" height="85" id="svg_7"/>
  <text fill="#000000" stroke="#000000" stroke-width="0" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x="390" y="53" id="svg_9" font-size="24" font-family="serif" text-anchor="middle" xml:space="preserve">Commit</text>
  <text fill="#000000" stroke="#000000" stroke-width="0" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x="89.83594" y="59.5" font-size="24" font-family="serif" text-anchor="middle" xml:space="preserve" id="svg_10">Commit</text>
  <text fill="#000000" stroke="#000000" stroke-width="0" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x="90.83594" y="106.5" font-size="24" font-family="serif" text-anchor="middle" xml:space="preserve" id="svg_11">Initial</text>
  <text fill="#000000" stroke="#000000" stroke-width="0" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x="389.83594" y="103.5" font-size="24" font-family="serif" text-anchor="middle" xml:space="preserve" id="svg_12">Models 1</text>
  <rect fill="#FF0000" stroke-width="5" x="104" y="156" width="116.00001" height="85" stroke="#000000" id="svg_16"/>
  <rect fill="#FF0000" stroke-width="5" x="331" y="156" width="116.00001" height="85" stroke="#000000" id="svg_17"/>
  <rect fill="#FF0000" stroke-width="5" x="102" y="274" width="116.00001" height="85" stroke="#000000" id="svg_18"/>
  <rect fill="#FF0000" stroke-width="5" x="333" y="272" width="116.00001" height="85" stroke="#000000" id="svg_19"/>
  <text fill="#000000" stroke="#000000" stroke-width="0" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x="162" y="180" id="svg_20" font-size="24" font-family="serif" text-anchor="middle" xml:space="preserve">Tree</text>
  <text fill="#000000" stroke="#000000" stroke-width="0" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x="386.82813" y="178.5" font-size="24" font-family="serif" text-anchor="middle" xml:space="preserve" id="svg_21">Tree</text>
  <text fill="#000000" stroke="#000000" stroke-width="0" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x="389.82813" y="298.5" font-size="24" font-family="serif" text-anchor="middle" xml:space="preserve" id="svg_22">Blob</text>
  <text fill="#000000" stroke="#000000" stroke-width="0" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x="153.82813" y="297.5" font-size="24" font-family="serif" text-anchor="middle" xml:space="preserve" id="svg_23">Blob</text>
  <text fill="#000000" stroke="#000000" stroke-width="0" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x="162" y="230" id="svg_24" font-size="24" font-family="serif" text-anchor="middle" xml:space="preserve">&lt;hash a&gt;</text>
  <text fill="#000000" stroke="#000000" stroke-width="0" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x="389.76563" y="228.5" font-size="24" font-family="serif" text-anchor="middle" xml:space="preserve" id="svg_25">&lt;hash b&gt;</text>
  <text fill="#000000" stroke="#000000" stroke-width="0" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x="160.76563" y="347.5" font-size="24" font-family="serif" text-anchor="middle" xml:space="preserve" id="svg_26">readme.md</text>
  <text fill="#000000" stroke="#000000" stroke-width="0" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x="393" y="347.5" font-size="24" font-family="serif" text-anchor="middle" xml:space="preserve" id="svg_27">test.txt</text>
  <text fill="#000000" stroke="#000000" stroke-width="0" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x="161" y="425" id="svg_28" font-size="24" font-family="serif" text-anchor="middle" xml:space="preserve">&lt;readme content&gt;</text>
  <text fill="#000000" stroke="#000000" stroke-width="0" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x="394.76563" y="424.5" font-size="24" font-family="serif" text-anchor="middle" xml:space="preserve" id="svg_29">&lt;empty&gt;</text>
  <line fill="none" stroke="#000000" stroke-width="5" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x1="86" y1="117" x2="162" y2="154" id="svg_32"/>
  <line fill="none" stroke="#000000" stroke-width="5" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x1="157" y1="241" x2="159" y2="277" id="svg_33"/>
  <line fill="none" stroke="#000000" stroke-width="5" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x1="388" y1="241" x2="217" y2="274" id="svg_34"/>
  <line fill="none" stroke="#000000" stroke-width="5" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x1="157" y1="361" x2="157" y2="410" id="svg_35"/>
  <line fill="none" stroke="#000000" stroke-width="5" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x1="391" y1="241" x2="391" y2="271" id="svg_36"/>
  <line fill="none" stroke="#000000" stroke-width="5" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x1="398" y1="359" x2="398" y2="412" id="svg_37"/>
  <line id="svg_1" y2="75" x2="146" y1="73" x1="330" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="5" stroke="#000000" fill="none"/>
  <line id="svg_2" y2="154" x2="388" y1="115" x1="389" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="5" stroke="#000000" fill="none"/>
  <rect id="svg_3" fill="#FF0000" stroke="#000000" stroke-width="5" x="562" y="30" width="114" height="85"/>
  <rect id="svg_5" fill="#FF0000" stroke-width="5" x="566" y="151" width="116.00001" height="85" stroke="#000000"/>
  <rect id="svg_6" fill="#FF0000" stroke-width="5" x="566" y="270" width="116.00001" height="85" stroke="#000000"/>
  <text id="svg_8" fill="#000000" stroke="#000000" stroke-width="0" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x="620.82813" y="176.5" font-size="24" font-family="serif" text-anchor="middle" xml:space="preserve">Tree</text>
  <text style="cursor: move;" id="svg_13" fill="#000000" stroke="#000000" stroke-width="0" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x="624.76563" y="226.5" font-size="24" font-family="serif" text-anchor="middle" xml:space="preserve">&lt;hash c&gt;</text>
  <text id="svg_14" fill="#000000" stroke="#000000" stroke-width="0" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x="625" y="296.5" font-size="24" font-family="serif" text-anchor="middle" xml:space="preserve">Blob</text>
  <text id="svg_15" fill="#000000" stroke="#000000" stroke-width="0" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x="627.33594" y="345.5" font-size="24" font-family="serif" text-anchor="middle" xml:space="preserve">test.txt</text>
  <text style="cursor: move;" id="svg_31" fill="#000000" stroke="#000000" stroke-width="0" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x="621" y="106.5" font-size="24" font-family="serif" text-anchor="middle" xml:space="preserve">Models 2</text>
  <text id="svg_38" fill="#000000" stroke="#000000" stroke-width="0" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x="620.83594" y="55.5" font-size="24" font-family="serif" text-anchor="middle" xml:space="preserve">Commit</text>
  <line id="svg_39" y2="69" x2="446" y1="67" x1="558" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="5" stroke="#000000" fill="none"/>
  <line id="svg_40" y2="149" x2="621" y1="118" x1="620" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="5" stroke="#000000" fill="none"/>
  <line id="svg_41" y2="271" x2="622" y1="237" x1="621" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="5" stroke="#000000" fill="none"/>
  <line id="svg_42" y2="277" x2="218" y1="235" x1="567" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="5" stroke="#000000" fill="none"/>
  <text style="cursor: move;" id="svg_43" fill="#000000" stroke="#000000" stroke-width="0" stroke-dasharray="null" stroke-linejoin="null" stroke-linecap="null" x="624.76563" y="420.5" font-size="24" font-family="serif" text-anchor="middle" xml:space="preserve">first test change</text>
  <line id="svg_44" y2="395" x2="624" y1="356" x1="623" stroke-linecap="null" stroke-linejoin="null" stroke-dasharray="null" stroke-width="5" stroke="#000000" fill="none"/>
 </g>
</svg>

## Branches
Branches are a kind of references, which is a map from names to hashes. Branches are nothing but references. In a sense, they simply point to a commit.<br>

You can see all branches, and your current one, with `> git branch`.<br>
You can switch branches with `> git checkout <branch-name>`<br>
You can delete a branch with `> git branch -D <branch-name>`. Make sure you're current branch is the one you're trying to delete.<br>
You can create a branch with `> git branch <branch-name>`.<br>
Since it's common to create a branch and switch to it, git has a shortcut: `> git checkout -b <branch-name>`.<br>
You can see a pretty commit history with `> git log --all --graph --decorate`

### Demo
1. Display the current commit graph 
1. Create new branch called `CoolNewFeature`
1. Switch to the new branch
1. Check that you have entered into the correct branch
1. `>> echo "cool new feature" >> test.txt`
1. `>> git add test.txt`
1. `>> git commit -m "Add Cool New Feature"`
1. Display the current commit graph following the commit in the branch
1. Switch back to the master branch
1. Confirm that `test.txt` is unchanged

## Merging (and Rebasing)
Merge occurs when independent lines of development combine into a single branch. It's very common to merge other branches with the master branch.

You can perform a merge of 2 branches with `> git merge <branch_name>`

Rebase is like merging except that it creates copies of the branch commits onto master. It allows for cleaner history because it will be a line.

You can perform a rebase operation with the master and one other branch with `> git rebase <source_branch> <feature_branch>`. **Make sure that the feature branch isn't a collaborative/shared branch.** Then, you simply merge the feature branch into the source branch. This will create a fast-forward merge, resulting in a linear commit history and no extra commit message.

### Demo
1. **<u>Task 1**</u> What kind of merge will happen if `CoolNewFeature` is merged into `master`?
1. `>> git checkout master`
1. `>> git merge CoolNewFeature`
1. **<u>Task 2**</u> What does the following command do?
1. `>> git branch -D CoolNewFeature`
1. `>> touch animal.py`
1. Copy the following code into `animal.py`:
    ```python
    def main():
        pass

    if __name__ == "__main__":
        main()
    ```
1. `>> git commit -am "Added animal.py"`
1. `>> git checkout -b dog`
1. Copy the following code above `def main()` in `animal.py`:
    ```python
    class Dog:
        def make_sound(self):
            print("woof")
    ```
1. Replace `def main()` in `animal.py` with:
    ```python
    def main():
        dog = Dog()
        dog.make_sound()
    ```
1. `>> git commit -am "Added dog"`
1. `>> git checkout master`
1. `>> git checkout -b duck`
1. Copy the following code above `def main()` in `animal.py`:
    ```python
    class Duck:
        def make_sound(self):
            print("KWAAK")
    ```
1. Replace `def main()` in `animal.py` with:
    ```python
    def main():
        duck = Duck()
        duck.make_sound()
    ```
1. `>> git commit -am "Added duck"`
1. `>> git checkout master`
1. `>> git checkout -b duck2`
1. Copy the following code above `def main()` in `animal.py`:
    ```python
    class Duck:
        def make_sound(self):
            print("quack")
    ```
1. Replace `def main()` in `animal.py` with:
    ```python
    def main():
        duck = Duck()
        duck.make_sound()
    ```
1. `>> git commit -am "Added duck2"`
1. `>> git checkout master`
1. Merge `dog` into `master`
1. Merge `duck` into `master`
1. **<u>Task 3</u>** Fix the merge conflicts such that both sounds are produced with `"woof"` being first.
    - If you find that you changed too much, you can always type `> git merge --abort` to stop the merge. You will simply go back to where you were before you typed `> git merge <branch-name>`.
1. Rebase `duck2` into `master`
1. **<u>Task 4</u>** Fix the merge conflicts such that both sounds are produced with `"woof"` being first. The duck has to make the proper sound.
    - If you find that you changed too much, you can always type `> git rebase --abort` to stop the rebase. You will simply go back to where you were before you typed `> git rebase <branch-name> <branch-name>`.
    - Because you are rebasing, there is a lot more to do. You're best bet to understand these is looking online. For this case, however, git is doing a pretty good job explaining what needs to be done.
    - Notice how you had to think about what to do here. You can't just simply include both changes. This doesn't have to do with the fact that you rebased. Rather, for any merge conflict, you need to really think about what you need to do.
1. Check the commit graph using `> git log --all --graph --decorate`
    - Do you see the difference between the rebase and the merge?


### Task Answers
#### Task 1:
Fast-forward
#### Task 2:
It deletes the `CoolNewFeature` branch
#### Task 3:
```python
class Dog:
    def make_sound(self):
        print("woof")
class Duck:
    def make_sound(self):
        print("KWAAK")

def main():
    dog = Dog()
    dog.make_sound()
    duck = Duck()
    duck.make_sound()

if __name__ == "__main__":
    main()`
```
#### Task 4:
```python
class Dog:
    def make_sound(self):
        print("woof")
class Duck:
    def make_sound(self):
        print("quack")

def main():
    dog = Dog()
    dog.make_sound()
    duck = Duck()
    duck.make_sound()

if __name__ == "__main__":
    main()`
```

## Revert and Reset
You have (for the most part) 3 kinds of "undos".<br>
`> git revert <commit-id>` is useful for a public repo. It will create new commit that is the same content as an old commit. This is to preserve history. **The `commit-id` is the commit you want to undo. NOT the commit you want to go back to.** This will only revert the *one* commit you specified. To revert a series of commits, use `> git revert <start_commit> <end_commit>`.<br>
`> git reset` is useful for a private branch. It will simply reset your `HEAD` to the specified commit. It is commonly used with the flags `--soft, --mixed, or --hard`. These will specify what happens to the index and working directory. Usually, you end up using `--hard` to clear out the index and the working directory.<br>
`> git checkout -- <file_name>` is useful when you're in the middle of working. While you are coding, if you accidentally change a file and you want to put it back to the previous commit, you can use this command. You can also do `> git checkout <commit_hashid> -- <file_name> to get a file from any other commit.


### Demo
1. Turns out our client liked the Kool™ way our duck KWAAKed. We need to go back.
1. **<u>Task 1</u>** Undo the duck2 change that made it sound like a duck. What command did you use for this?
1. `>> git checkout -b cat`
1. Copy the following code above `def main()` in `animal.py`:
    ```python
    class Cat:
        def make_sound(self):
            print("moo")
    ```
1. Replace `def main()` in `animal.py` with:
    ```python
    def main():
        dog = Dog()
        dog.make_sound()
        cat = Cat()
        cat.make_sound()
    ```
1. `>> git commit -am "Added cat"`
1. Wait a minute, cats don't "moo." We need to undo this. But using the previous command will let the whole world know about this foolish mistake when it is eventually merged into master.
1. **<u>Task 2</u>** Undo the cat mistake without letting anyone ever know you made it. What command did you use?
1. Put the cat behavior back in, but with the cat saying "meow" instead and commit it.
1. `>> head /dev/urandom > animal.py`
1. Oops. Good thing we caught this mistake before we committed.
1. **<u>Task 3</u>** Undo the file destruction. What command did you use?

### Task Answers
#### Task 1:
`>> git revert <commit id of "Added Duck2">`
#### Task 2:
`>> git reset --hard <commit id of "Merge conflict resolved">`
#### Task 3:
`>> git checkout -- animal.py`

