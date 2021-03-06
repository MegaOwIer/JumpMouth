#include <stdbool.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct splayNode {
	struct splayNode *son[2], *fa;
	int val, siz, cnt;
} splayNode;

splayNode* newNode(int val) {
	splayNode *cur = (splayNode*)malloc(sizeof(splayNode));
	cur -> val = val;
	cur -> siz = cur -> cnt = 0;
	cur -> fa = NULL;
	cur -> son[0] = cur -> son[1] = NULL;
	return cur;
}

int dir(splayNode *o) {return o == o -> fa -> son[1];}

void maintain(splayNode *o) {
	o -> siz = o -> cnt;
	for(int i = 0; i < 2; i++) if(o -> son[i] != NULL) {
		o -> siz += o -> son[i] -> siz;
		o -> son[i] -> fa = o;
	}
}

void rotate(splayNode *o) {
	splayNode *f = o -> fa;
	int d = dir(o);
	f -> son[d] = o -> son[d ^ 1];
	o -> son[d ^ 1] = f;
	o -> fa = f -> fa;
	if(o -> fa) {
		o -> fa -> son[dir(f)] = o;
	}
	maintain(f);
}

void splay(splayNode **root, splayNode *o) {
	while(o -> fa != NULL) {
		splayNode *f = o -> fa;
		if(f -> fa == NULL) {
			rotate(o);
		} else if(dir(f) == dir(o)) {
			rotate(f), rotate(o);
		} else {
			rotate(o), rotate(o);
		}
	}
	maintain(o);
	*root = o;
}

void insert(splayNode **root, splayNode *o, int val) {
	while(o -> val != val) {
		int cmp = val > o -> val;
		if(o -> son[cmp] == NULL) {
			o -> son[cmp] = newNode(val);
			o -> son[cmp] -> fa = o;
		}
		o = o -> son[cmp];
	}
	o -> cnt += 1;
	splay(root, o);
}

void delete(splayNode **root, int val) {
	if((*root) -> son[0] == NULL && (*root) -> son[1] == NULL) {
		free(*root);
		*root = NULL;
		return;
	}
	splayNode *o = *root;
	while(o -> val != val) {
		o = o -> son[val > o -> val];
	}
	splay(root, o);
	if(o -> cnt > 1) {
		o -> cnt -= 1;
		o -> siz -= 1;
	} else if(o -> son[0] == NULL) {
		*root = o -> son[1];
		free(o);
		(*root) -> fa = NULL;
	} else if(o -> son[1] == NULL) {
		*root = o -> son[0];
		free(o);
		(*root) -> fa = NULL;
	} else {
		o = (*root) -> son[0];
		while(o -> son[1]) {
			o = o -> son[1];
		}
		splay(root, o);
		(*root) -> son[1] = (*root) -> son[1] -> son[1];
		free((*root) -> son[1] -> fa);
		maintain(*root);
	}
}

int getKth(splayNode *o, int rank) {
	while(true) {
		if(!o -> son[0]) {
			if(rank <= o -> cnt) return o -> val;
			rank -= o -> cnt;
			o = o -> son[1];
		} else if(rank <= o -> son[0] -> siz) {
			o = o -> son[0];
		} else if(rank <= o -> son[0] -> siz + o -> cnt) {
			return o -> val;
		} else {
			rank -= o -> son[0] -> siz + o -> cnt;
			o = o -> son[1];
		}
	}
}

int getRank(splayNode *o, int val) {
	int ans = -1;
	while(o != NULL) {
		if(o -> val < val) {
			ans += o -> cnt + (o -> son[0] ? o -> son[0] -> siz : 0);
			o = o -> son[1];
		} else {
			o = o -> son[0];
		}
	}
	return ans;
}

int getNumber(splayNode **root, int val, int f) {
	splayNode *o = *root;
	while(o -> val != val) {
		int d = val > o -> val;
		if(o -> son[d] == NULL) break;
		o = o -> son[d];
	}
	splay(root, o);
	if(f == 1 && o -> val > val) return o -> val;
	if(f == 0 && o -> val < val) return o -> val;
	o = o -> son[f];
	while(o -> son[f ^ 1] != NULL) {
		o = o -> son[f ^ 1];
	}
	return o -> val;
}

int main() {
	int n;
	scanf("%d", &n);
	splayNode *root = newNode(-1);
	root -> siz = root -> cnt = 1;
	insert(&root, root, INT_MAX);
	while(n--) {
		int op, x, ans;
		scanf("%d%d", &op, &x);
		switch(op) {
			case 0:
				insert(&root, root, x);
				break;
			case 1:
				delete(&root, x);
				break;
			case 2:
				printf("%d\n", getKth(root, x + 1));
				break;
			case 3:
				printf("%d\n", getRank(root, x));
				break;
			default:
				ans = getNumber(&root, x, op - 4);
				if(ans == INT_MAX) ans = -1;
				printf("%d\n", ans);
		}
	}
	return 0;
}
