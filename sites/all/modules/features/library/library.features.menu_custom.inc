<?php
/**
 * @file
 * library.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function library_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-librarian-menu.
  $menus['menu-librarian-menu'] = array(
    'menu_name' => 'menu-librarian-menu',
    'title' => 'Librarian Menu',
    'description' => '',
  );
  // Exported menu: menu-user.
  $menus['menu-user'] = array(
    'menu_name' => 'menu-user',
    'title' => 'User Menu',
    'description' => 'Menu for the user',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Librarian Menu');
  t('Menu for the user');
  t('User Menu');

  return $menus;
}
