<?php

/**
 * @file
 *   This file provides a CTools content type containing the author pane.
 */

/**
 * Implements hook_ctools_content_types().
 */
function facebook_status_facebook_status_stream_ctools_content_types() {
  return array(
    'single' => TRUE,
    'title' => t('Facebook-style Statuses Stream'),
    'icon' => 'icon_user.png',
    'description' => t('A stream of Facebook-style Statuses.'),
    'required context' => new ctools_context_required(t('Miscellaneous'), 'misc'), //@todo: Is this needed?
    'category' => t('Miscellaneous'),
  );
}

/**
 * Implements hook_content_type_render().
 */
function facebook_status_facebook_status_stream_content_type_render($subtype, $conf, $panel_args, $context) {
  $account = isset($context->data) ? clone $context->data : NULL;
  $block = new stdClass();
  $block->content = t('User information is currently unavailable.');
  if ($account) {
    $block->title = t("Stream");
    // TODO Please change this theme call to use an associative array for the $variables parameter.
    $block->content = theme('facebook_status_form_display');
  }
  return $block;
}

/**
 * Implements hook_content_type_admin_title().
 */
function facebook_status_facebook_status_stream_content_type_admin_title($subtype, $conf, $context) {
  return t('Stream');
}
