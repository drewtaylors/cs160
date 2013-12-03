
test:     file format elf32-i386


Disassembly of section .init:

08048338 <_init>:
 8048338:	53                   	push   %ebx
 8048339:	83 ec 08             	sub    $0x8,%esp
 804833c:	e8 7f 00 00 00       	call   80483c0 <__x86.get_pc_thunk.bx>
 8048341:	81 c3 bf 1c 00 00    	add    $0x1cbf,%ebx
 8048347:	8b 83 fc ff ff ff    	mov    -0x4(%ebx),%eax
 804834d:	85 c0                	test   %eax,%eax
 804834f:	74 05                	je     8048356 <_init+0x1e>
 8048351:	e8 1a 00 00 00       	call   8048370 <__gmon_start__@plt>
 8048356:	83 c4 08             	add    $0x8,%esp
 8048359:	5b                   	pop    %ebx
 804835a:	c3                   	ret    

Disassembly of section .plt:

08048360 <__gmon_start__@plt-0x10>:
 8048360:	ff 35 04 a0 04 08    	pushl  0x804a004
 8048366:	ff 25 08 a0 04 08    	jmp    *0x804a008
 804836c:	00 00                	add    %al,(%eax)
	...

08048370 <__gmon_start__@plt>:
 8048370:	ff 25 0c a0 04 08    	jmp    *0x804a00c
 8048376:	68 00 00 00 00       	push   $0x0
 804837b:	e9 e0 ff ff ff       	jmp    8048360 <_init+0x28>

08048380 <__libc_start_main@plt>:
 8048380:	ff 25 10 a0 04 08    	jmp    *0x804a010
 8048386:	68 08 00 00 00       	push   $0x8
 804838b:	e9 d0 ff ff ff       	jmp    8048360 <_init+0x28>

Disassembly of section .text:

08048390 <_start>:
 8048390:	31 ed                	xor    %ebp,%ebp
 8048392:	5e                   	pop    %esi
 8048393:	89 e1                	mov    %esp,%ecx
 8048395:	83 e4 f0             	and    $0xfffffff0,%esp
 8048398:	50                   	push   %eax
 8048399:	54                   	push   %esp
 804839a:	52                   	push   %edx
 804839b:	68 30 85 04 08       	push   $0x8048530
 80483a0:	68 c0 84 04 08       	push   $0x80484c0
 80483a5:	51                   	push   %ecx
 80483a6:	56                   	push   %esi
 80483a7:	68 8c 84 04 08       	push   $0x804848c
 80483ac:	e8 cf ff ff ff       	call   8048380 <__libc_start_main@plt>
 80483b1:	f4                   	hlt    
 80483b2:	66 90                	xchg   %ax,%ax
 80483b4:	66 90                	xchg   %ax,%ax
 80483b6:	66 90                	xchg   %ax,%ax
 80483b8:	66 90                	xchg   %ax,%ax
 80483ba:	66 90                	xchg   %ax,%ax
 80483bc:	66 90                	xchg   %ax,%ax
 80483be:	66 90                	xchg   %ax,%ax

080483c0 <__x86.get_pc_thunk.bx>:
 80483c0:	8b 1c 24             	mov    (%esp),%ebx
 80483c3:	c3                   	ret    
 80483c4:	66 90                	xchg   %ax,%ax
 80483c6:	66 90                	xchg   %ax,%ax
 80483c8:	66 90                	xchg   %ax,%ax
 80483ca:	66 90                	xchg   %ax,%ax
 80483cc:	66 90                	xchg   %ax,%ax
 80483ce:	66 90                	xchg   %ax,%ax

080483d0 <deregister_tm_clones>:
 80483d0:	b8 1b a0 04 08       	mov    $0x804a01b,%eax
 80483d5:	2d 18 a0 04 08       	sub    $0x804a018,%eax
 80483da:	83 f8 06             	cmp    $0x6,%eax
 80483dd:	77 02                	ja     80483e1 <deregister_tm_clones+0x11>
 80483df:	f3 c3                	repz ret 
 80483e1:	b8 00 00 00 00       	mov    $0x0,%eax
 80483e6:	85 c0                	test   %eax,%eax
 80483e8:	74 f5                	je     80483df <deregister_tm_clones+0xf>
 80483ea:	55                   	push   %ebp
 80483eb:	89 e5                	mov    %esp,%ebp
 80483ed:	83 ec 18             	sub    $0x18,%esp
 80483f0:	c7 04 24 18 a0 04 08 	movl   $0x804a018,(%esp)
 80483f7:	ff d0                	call   *%eax
 80483f9:	c9                   	leave  
 80483fa:	c3                   	ret    
 80483fb:	90                   	nop
 80483fc:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi

08048400 <register_tm_clones>:
 8048400:	b8 18 a0 04 08       	mov    $0x804a018,%eax
 8048405:	2d 18 a0 04 08       	sub    $0x804a018,%eax
 804840a:	c1 f8 02             	sar    $0x2,%eax
 804840d:	89 c2                	mov    %eax,%edx
 804840f:	c1 ea 1f             	shr    $0x1f,%edx
 8048412:	01 d0                	add    %edx,%eax
 8048414:	d1 f8                	sar    %eax
 8048416:	75 02                	jne    804841a <register_tm_clones+0x1a>
 8048418:	f3 c3                	repz ret 
 804841a:	ba 00 00 00 00       	mov    $0x0,%edx
 804841f:	85 d2                	test   %edx,%edx
 8048421:	74 f5                	je     8048418 <register_tm_clones+0x18>
 8048423:	55                   	push   %ebp
 8048424:	89 e5                	mov    %esp,%ebp
 8048426:	83 ec 18             	sub    $0x18,%esp
 8048429:	89 44 24 04          	mov    %eax,0x4(%esp)
 804842d:	c7 04 24 18 a0 04 08 	movl   $0x804a018,(%esp)
 8048434:	ff d2                	call   *%edx
 8048436:	c9                   	leave  
 8048437:	c3                   	ret    
 8048438:	90                   	nop
 8048439:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi

08048440 <__do_global_dtors_aux>:
 8048440:	80 3d 18 a0 04 08 00 	cmpb   $0x0,0x804a018
 8048447:	75 13                	jne    804845c <__do_global_dtors_aux+0x1c>
 8048449:	55                   	push   %ebp
 804844a:	89 e5                	mov    %esp,%ebp
 804844c:	83 ec 08             	sub    $0x8,%esp
 804844f:	e8 7c ff ff ff       	call   80483d0 <deregister_tm_clones>
 8048454:	c6 05 18 a0 04 08 01 	movb   $0x1,0x804a018
 804845b:	c9                   	leave  
 804845c:	f3 c3                	repz ret 
 804845e:	66 90                	xchg   %ax,%ax

08048460 <frame_dummy>:
 8048460:	a1 f8 9e 04 08       	mov    0x8049ef8,%eax
 8048465:	85 c0                	test   %eax,%eax
 8048467:	74 1e                	je     8048487 <frame_dummy+0x27>
 8048469:	b8 00 00 00 00       	mov    $0x0,%eax
 804846e:	85 c0                	test   %eax,%eax
 8048470:	74 15                	je     8048487 <frame_dummy+0x27>
 8048472:	55                   	push   %ebp
 8048473:	89 e5                	mov    %esp,%ebp
 8048475:	83 ec 18             	sub    $0x18,%esp
 8048478:	c7 04 24 f8 9e 04 08 	movl   $0x8049ef8,(%esp)
 804847f:	ff d0                	call   *%eax
 8048481:	c9                   	leave  
 8048482:	e9 79 ff ff ff       	jmp    8048400 <register_tm_clones>
 8048487:	e9 74 ff ff ff       	jmp    8048400 <register_tm_clones>

0804848c <main>:
 804848c:	55                   	push   %ebp
 804848d:	89 e5                	mov    %esp,%ebp
 804848f:	83 ec 10             	sub    $0x10,%esp
 8048492:	c7 45 fc 05 00 00 00 	movl   $0x5,-0x4(%ebp)
 8048499:	83 7d fc 05          	cmpl   $0x5,-0x4(%ebp)
 804849d:	75 09                	jne    80484a8 <main+0x1c>
 804849f:	c7 45 fc 06 00 00 00 	movl   $0x6,-0x4(%ebp)
 80484a6:	eb 07                	jmp    80484af <main+0x23>
 80484a8:	c7 45 fc 09 00 00 00 	movl   $0x9,-0x4(%ebp)
 80484af:	b8 00 00 00 00       	mov    $0x0,%eax
 80484b4:	c9                   	leave  
 80484b5:	c3                   	ret    
 80484b6:	66 90                	xchg   %ax,%ax
 80484b8:	66 90                	xchg   %ax,%ax
 80484ba:	66 90                	xchg   %ax,%ax
 80484bc:	66 90                	xchg   %ax,%ax
 80484be:	66 90                	xchg   %ax,%ax

080484c0 <__libc_csu_init>:
 80484c0:	55                   	push   %ebp
 80484c1:	57                   	push   %edi
 80484c2:	31 ff                	xor    %edi,%edi
 80484c4:	56                   	push   %esi
 80484c5:	53                   	push   %ebx
 80484c6:	e8 f5 fe ff ff       	call   80483c0 <__x86.get_pc_thunk.bx>
 80484cb:	81 c3 35 1b 00 00    	add    $0x1b35,%ebx
 80484d1:	83 ec 1c             	sub    $0x1c,%esp
 80484d4:	8b 6c 24 30          	mov    0x30(%esp),%ebp
 80484d8:	8d b3 f4 fe ff ff    	lea    -0x10c(%ebx),%esi
 80484de:	e8 55 fe ff ff       	call   8048338 <_init>
 80484e3:	8d 83 f0 fe ff ff    	lea    -0x110(%ebx),%eax
 80484e9:	29 c6                	sub    %eax,%esi
 80484eb:	c1 fe 02             	sar    $0x2,%esi
 80484ee:	85 f6                	test   %esi,%esi
 80484f0:	74 27                	je     8048519 <__libc_csu_init+0x59>
 80484f2:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
 80484f8:	8b 44 24 38          	mov    0x38(%esp),%eax
 80484fc:	89 2c 24             	mov    %ebp,(%esp)
 80484ff:	89 44 24 08          	mov    %eax,0x8(%esp)
 8048503:	8b 44 24 34          	mov    0x34(%esp),%eax
 8048507:	89 44 24 04          	mov    %eax,0x4(%esp)
 804850b:	ff 94 bb f0 fe ff ff 	call   *-0x110(%ebx,%edi,4)
 8048512:	83 c7 01             	add    $0x1,%edi
 8048515:	39 f7                	cmp    %esi,%edi
 8048517:	75 df                	jne    80484f8 <__libc_csu_init+0x38>
 8048519:	83 c4 1c             	add    $0x1c,%esp
 804851c:	5b                   	pop    %ebx
 804851d:	5e                   	pop    %esi
 804851e:	5f                   	pop    %edi
 804851f:	5d                   	pop    %ebp
 8048520:	c3                   	ret    
 8048521:	eb 0d                	jmp    8048530 <__libc_csu_fini>
 8048523:	90                   	nop
 8048524:	90                   	nop
 8048525:	90                   	nop
 8048526:	90                   	nop
 8048527:	90                   	nop
 8048528:	90                   	nop
 8048529:	90                   	nop
 804852a:	90                   	nop
 804852b:	90                   	nop
 804852c:	90                   	nop
 804852d:	90                   	nop
 804852e:	90                   	nop
 804852f:	90                   	nop

08048530 <__libc_csu_fini>:
 8048530:	f3 c3                	repz ret 
 8048532:	66 90                	xchg   %ax,%ax

Disassembly of section .fini:

08048534 <_fini>:
 8048534:	53                   	push   %ebx
 8048535:	83 ec 08             	sub    $0x8,%esp
 8048538:	e8 83 fe ff ff       	call   80483c0 <__x86.get_pc_thunk.bx>
 804853d:	81 c3 c3 1a 00 00    	add    $0x1ac3,%ebx
 8048543:	83 c4 08             	add    $0x8,%esp
 8048546:	5b                   	pop    %ebx
 8048547:	c3                   	ret    
